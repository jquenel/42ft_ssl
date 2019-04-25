/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_md5_fillbuf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:32:08 by jquenel           #+#    #+#             */
/*   Updated: 2019/04/22 19:55:38 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"

static int	pad(t_md5 *context, int count, int ispadding)
{
	if (!ispadding)
	{
		context->buf[count] = 0x80;
		count++;
	}
	ft_bzero(&(context->buf[count]), 56 - count);
	ssl_md5_encode(((uint32_t *)&(context->flen))[0], 
			&(context->buf[56]), context->endian);
	ssl_md5_encode(((uint32_t *)&(context->flen))[1],
			&(context->buf[60]), context->endian);
	return (-1);
}

int			read_from_src(t_md5 *context, char const *src, int i)
{
	static int	ispadding = 0;
	int			count;

	if (ispadding != 0 && !(ispadding = 0))
		return (pad(context, 0, 1));
	if (!src)
		return (-2);
	count = 0;
	while (count < 64 && src[i + count])
	{
		context->buf[count] = src[i + count];
		count++;
	}
	context->flen += count * 8;
	if (count < 55)
		return (pad(context, count, 0));
	else if (count < 64)
	{
		context->buf[count] = 0x80;
		ft_bzero(&(context->buf[count]), 64 - (count + 1));
		ispadding = 1;
		return (i + count);
	}
	else
		return (i + count);
}

int			ssl_md5_fillbuf(t_md5 *context, char const *src, int i, int fd)
{
	static int	ispadding = 0;
	int			count;

	if (ispadding != 0 && !(ispadding = 0))
		return (pad(context, 0, 1));
	if (fd != -1)
	{
		if ((count = read(fd, context->buf, 64)) == -1)
			return (-2);
		context->flen += count * 8;
		if (count < 55)
			return (pad(context, count, 0));
		else if (count < 64)
		{
			context->buf[count] = 0x80;
			ft_bzero(&(context->buf[count]), 64 - (count + 1));
			ispadding = 1;
			return (i + count);
		}
		else
			return (i + count);
	}
	else
		return (read_from_src(context, src, i));
}
