/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:21:04 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:21:10 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_ssl.h"

uint32_t		ft_rotr32(uint32_t word, uint32_t shift)
{
	return ((word >> shift) | (word << (32 - shift)));
}

uint64_t		ft_rotr64(uint64_t word, uint64_t shift)
{
	return ((word >> shift) | (word << (64 - shift)));
}
