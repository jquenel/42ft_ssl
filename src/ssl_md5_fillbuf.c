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

#include "ssl_dgst.h"

static int	pad(t_md5 *context, int count)
{
	return (-1);
}

int			ssl_md5_fillbuf(t_md5 *context, char *src, int i, int fd)
{
	static int	ispadding = 0;
	int			count;

	if (ispadding != 0)
	{
		ispadding = 1;
		return (pad(context, 0));
	}
	if (fd != -1)
	{
		if ((count = read(fd, context->buf, 512)) == -1);
			return (-2);
		context->flen += count;
		if (count < 512 - 64)
			return (pad(context, count));
		else if (count < 512)
		{
			ft_bzero(&(((char *)context->buf)[count]), 512 - count);
			ispadding = 1;
			return (count);
		}
	}
		

}
