/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_sha224.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:37:07 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/08 18:13:01 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libargc.h"
#include "ft_ssl.h"
#include "ssl_dgst.h"

static void	ssl_sha224_reset(t_dgst32 *context)
{
	ft_bzero(context->buf, 64);
	context->flen = 0;
	context->words[0] = 0xc1059ed8;
	context->words[1] = 0x367cd507;
	context->words[2] = 0x3070dd17;
	context->words[3] = 0xf70e5939;
	context->words[4] = 0xffc00b31;
	context->words[5] = 0x68581511;
	context->words[6] = 0x64f98fa7;
	context->words[7] = 0xbefa4fa4;
}

static int	sha224_run(t_dgst32 *context, int fd, t_arg *arg, int *flags)
{
	char			*fname;
	int				i;

	fname = arg ? (char *)arg->strcnt : NULL;
	ssl_sha224_reset(context);
	i = 0;
	while ((i = ssl_dgst32_fillbuf(context, fname, i, fd)) > -1)
		ssl_sha256_update(context);
	if (i == -2)
		return (i);
	ssl_sha256_update(context);
	ssl_sha224_print(context, fname, arg ? arg->flag : 0, flags);
	return (i);
}

int			ssl_sha224(t_arg *args, int flags)
{
	t_dgst32	*context;
	int			fd;

	if (!(context = ssl_dgst32_init(SHA2_HASHLEN, flags)))
		return (0);
	if (flags & (DGST_FLAG_STDIN | DGST_FLAG_NOARG))
		sha224_run(context, 0, args, &flags);
	while (args)
	{
		if (args->flag & DGST_FLAG_STRARG)
			sha224_run(context, -1, args, &flags);
		else if (!args->flag && args->strcnt)
		{
			if ((fd = open(args->strcnt, O_RDONLY)) == -1)
				ssl_nofile("sha224: ", args->strcnt);
			else
			{
				sha224_run(context, fd, args, &flags);
				close(fd);
			}
		}
		args = args->next;
	}
	ssl_dgst32_del(context);
	return (1);
}
