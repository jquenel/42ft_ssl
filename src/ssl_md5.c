/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_md5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:29:27 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/08 18:12:27 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libargc.h"
#include "ft_ssl.h"
#include "ssl_dgst.h"

static void	ssl_md5_reset(t_dgst32 *context)
{
	ft_bzero(context->buf, 64);
	context->words[0] = 0x67452301;
	context->words[1] = 0xefcdab89;
	context->words[2] = 0x98badcfe;
	context->words[3] = 0x10325476;
	context->flen = 0;
}

static int	md5_run(t_dgst32 *context, int fd, t_arg *arg, int *flags)
{
	char	*fname;
	int		i;

	fname = arg ? (char *)arg->strcnt : NULL;
	ssl_md5_reset(context);
	i = 0;
	while ((i = ssl_dgst32_fillbuf(context, fname, i, fd)) > -1)
		ssl_md5_update(context);
	if (i == -2)
		return (i);
	ssl_md5_update(context);
	ssl_md5_print(context, fname, arg ? arg->flag : 0, flags);
	ssl_md5_reset(context);
	return (i);
}

int			ssl_md5(t_arg *args, int flags)
{
	t_dgst32	*context;
	int			fd;

	if (!(context = ssl_dgst32_init(MD5_HASHLEN, flags)))
		return (0);
	if (flags & (DGST_FLAG_STDIN | DGST_FLAG_NOARG))
		md5_run(context, 0, args, &flags);
	while (args)
	{
		if (args->flag & DGST_FLAG_STRARG)
			md5_run(context, -1, args, &flags);
		else if (!args->flag && args->strcnt)
		{
			if ((fd = open(args->strcnt, O_RDONLY)) == -1)
				ssl_nofile("md5: ", args->strcnt);
			else
			{
				md5_run(context, fd, args, &flags);
				close(fd);
			}
		}
		args = args->next;
	}
	ssl_dgst32_del(context);
	return (1);
}
