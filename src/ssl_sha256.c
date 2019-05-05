/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_sha256.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:36:40 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:36:41 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libargc.h"
#include "ft_ssl.h"
#include "ssl_dgst.h"

static void	ssl_sha256_reset(t_dgst32 *context)
{
	ft_bzero(context->buf, 64);
	context->flen = 0;
	context->words[0] = 0x6a09e667;
	context->words[1] = 0xbb67ae85;
	context->words[2] = 0x3c6ef372;
	context->words[3] = 0xa54ff53a;
	context->words[4] = 0x510e527f;
	context->words[5] = 0x9b05688c;
	context->words[6] = 0x1f83d9ab;
	context->words[7] = 0x5be0cd19;
}

static int	sha256_run(t_dgst32 *context, int fd, t_arg *arg, int *flags)
{
	int				i;
	char			*fname;

	fname = arg ? (char *)arg->strcnt : NULL;
	ssl_sha256_reset(context);
	i = 0;
	while ((i = ssl_dgst32_fillbuf(context, fname, i, fd)) > -1)
		ssl_sha256_update(context);
	if (i == -2)
		return (i);
	ssl_sha256_update(context);
	ssl_sha256_print(context, fname, arg ? arg->flag : 0, flags);
	return (i);
}

int			ssl_sha256(t_arg *args, int flags)
{
	t_dgst32	*context;
	int			fd;

	if (!(context = ssl_dgst32_init(SHA2_HASHLEN, flags)))
		return (0);
	if (flags & (DGST_FLAG_STDIN | DGST_FLAG_NOARG))
		sha256_run(context, 0, args, &flags);
	while (args)
	{
		if (args->flag & DGST_FLAG_STRARG)
			sha256_run(context, -1, args, &flags);
		else if (!args->flag && args->strcnt)
		{
			if ((fd = open(args->strcnt, O_RDONLY)) == -1)
				ssl_nofile("sha256: ", args->strcnt);
			else
			{
				sha256_run(context, fd, args, &flags);
				close(fd);
			}
		}
		args = args->next;
	}
	ssl_dgst32_del(context);
	return (1);
}
