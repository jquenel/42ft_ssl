/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_dgst32_fillbuf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:23:11 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:24:08 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"

static int	pad(t_dgst32 *context, int count, int ispadding)
{
	if (!ispadding)
	{
		context->buf[count] = 0x80;
		count++;
	}
	ft_bzero(&(context->buf[count]), 56 - count);
	if (context->hashlen == 8)
		ssl_sha2_encode64(context->flen, &(context->buf[56]));
	else
		ssl_md5_encode(context->flen, &(context->buf[56]));
	return (-1);
}

static int	read_from_x(t_dgst32 *context, char const *src, int i, int fd)
{
	int		count;

	count = 0;
	if (fd == 0)
	{
		count = ft_read_stdin((char *)context->buf, 64);
		if ((context->flags & DGST_FLAG_STDIN) && !(isatty(0)))
			write(1, context->buf, count);
		return (count);
	}
	else if (fd > 0)
		return (read(fd, context->buf, 64));
	else
	{
		if (!src)
			return (-1);
		while (count < 64 && src[i + count])
		{
			context->buf[count] = src[i + count];
			count++;
		}
		return (count);
	}
}

int			ssl_dgst32_fillbuf(t_dgst32 *context, char const *src, \
							int i, int fd)
{
	static int	ispadding = 0;
	int			count;

	if (ispadding != 0 && !(ispadding = 0))
		return (pad(context, 0, 1));
	if ((count = read_from_x(context, src, i, fd)) == -1)
		return (-2);
	context->flen += count * 8;
	if (count < 55)
		return (pad(context, count, 0));
	else if (count < 64)
	{
		context->buf[count] = 0x80;
		count++;
		ft_bzero(&(context->buf[count]), 64 - count);
		ispadding = 1;
		return (i + count);
	}
	else
		return (i + count);
}
