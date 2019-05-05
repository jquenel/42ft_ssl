/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:33:25 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:33:26 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_ssl.h"

uint32_t		ft_rotl32(uint32_t word, uint32_t shift)
{
	return ((word << shift) | (word >> (32 - shift)));
}

uint64_t		ft_rotl64(uint64_t word, uint64_t shift)
{
	return ((word << shift) | (word >> (64 - shift)));
}
