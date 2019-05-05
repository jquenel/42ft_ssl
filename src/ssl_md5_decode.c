/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_md5_decode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:29:18 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:29:19 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ssl_dgst.h"

uint32_t		ssl_md5_decode(unsigned char *input)
{
	return (((uint32_t)input[0] & 0xff)
				| (((uint32_t)input[1] & 0xff) << 8)
				| (((uint32_t)input[2] & 0xff) << 16)
				| (((uint32_t)input[3] & 0xff) << 24));
}
