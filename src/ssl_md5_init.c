/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_md5_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:07:17 by jquenel           #+#    #+#             */
/*   Updated: 2019/04/22 19:40:10 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"

t_md5				*ssl_md5_init(void)
{
	t_md5		*context;

	if (!(context = malloc(sizeof(context))))
		return (NULL);
	if (!(context->buf = malloc(sizeof(char) * 64))
		|| !(context->words = malloc(sizeof(uint32_t) * 4)))
		return (NULL);
	context->words[0] = 0x67452301;
	context->words[1] = 0xefcdab89;
	context->words[2] = 0x98badcfe;
	context->words[3] = 0x10325476;
	context->flen = 0;
	ft_bzero(context->buf, sizeof(char) * 64);
	context->endian = ft_endian();
	return (context);
}
