/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_md5_encode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:35:52 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:35:53 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"

void		ssl_md5_encode(uint64_t n, unsigned char *s)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		s[i] = (unsigned char)((n >> (i * 8)) & 0xff);
		i++;
	}
}
