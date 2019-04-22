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

static int	pad(t_md5 *context, int count)
{
	int		i;

	while (count < (512 - 64) / 8)
	{
		((char *)context->buf)[count] = 0;
		count++;
	}
	i = 0;
	while (i < 64 / 8)
	{
		((char *)context->buf)[count + i] = ((char *)context->flen)[i];
		i++;
	}
	return (-1);
}

int			read_from_src(t_md5 *context, char const *src, int i)
{
	static int	ispadding = 0;
	int			count;

	if (ispadding != 0 && !(ispadding = 0))
		return (pad(context, 0));
	if (!src)
		return (-2);
	count = 0;
	while (count < 512 / 8 && src[i + count])
	{
		((char *)context->buf)[count] = src[i + count];
		count++;
	}
	context->flen += count;
	if (count < (512 / 64) / 8)
		return (pad(context, count));
	else if (count < 512 / 8)
	{
		ft_bzero(&(((char *)context->buf)[count]), (512 / 8) - count);
		ispadding = 1;
		return (i + count);
	}
	else
		return (i + count);
	return (-2);
}

int			ssl_md5_fillbuf(t_md5 *context, char const *src, int i, int fd)
{
	static int	ispadding = 0;
	int			count;

	if (ispadding != 0 && !(ispadding = 0))
		return (pad(context, 0));
	if (fd != -1)
	{
		if ((count = read(fd, context->buf, 512 / 8)) == -1)
			return (-2);
		context->flen += count;
		if (count < (512 - 64) / 8)
			return (pad(context, count));
		else if (count < 512 / 8)
		{
			ft_bzero(&(((char *)context->buf)[count]), (512 / 8) - count);
			ispadding = 1;
			return (i + count);
		}
	}
	else
		return (read_from_src(context, src, i));
	return (-2);
}
