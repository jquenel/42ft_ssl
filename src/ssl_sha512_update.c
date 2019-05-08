/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_sha512_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:28:59 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/08 18:14:33 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"
#include "ssl_dgst_const.h"

static uint64_t	ch(uint64_t e, uint64_t f, uint64_t g)
{
	return ((e & f) ^ ((~e) & g));
}

static uint64_t	maj(uint64_t a, uint64_t b, uint64_t c)
{
	return ((a & b) ^ (a & c) ^ (b & c));
}

static void		sha512_dgst(uint64_t w[64], uint64_t h[8], int i)
{
	uint64_t	s0;
	uint64_t	s1;
	uint64_t	t0;
	uint64_t	t1;

	s0 = ft_rotr64(h[0], 28) ^ ft_rotr64(h[0], 34) ^ ft_rotr64(h[0], 39);
	s1 = ft_rotr64(h[4], 14) ^ ft_rotr64(h[4], 18) ^ ft_rotr64(h[4], 41);
	t0 = h[7] + s1 + ch(h[4], h[5], h[6]) + g_sha512_k[i] + w[i];
	t1 = s0 + maj(h[0], h[1], h[2]);
	h[7] = h[6];
	h[6] = h[5];
	h[5] = h[4];
	h[4] = h[3] + t0;
	h[3] = h[2];
	h[2] = h[1];
	h[1] = h[0];
	h[0] = t0 + t1;
}

static void		prepare_sha512(uint64_t w[64], uint64_t h[8], t_dgst64 *context)
{
	uint64_t	s0;
	uint64_t	s1;
	int			i;

	i = 0;
	while (i < 16)
	{
		w[i] = ssl_sha2_decode64(&(context->buf[i * 8]));
		i++;
	}
	while (i < 80)
	{
		s0 = ft_rotr64(w[i - 15], 1) ^ ft_rotr64(w[i - 15], 8)
			^ (w[i - 15] >> 7);
		s1 = ft_rotr64(w[i - 2], 19) ^ ft_rotr64(w[i - 2], 61)
			^ (w[i - 2] >> 6);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		i++;
	}
	i = 0;
	while (i < 8)
	{
		h[i] = context->words[i];
		i++;
	}
}

void			ssl_sha512_update(t_dgst64 *context)
{
	uint64_t	w[80];
	uint64_t	h[8];
	int			i;

	ft_bzero(w, sizeof(uint64_t) * 80);
	prepare_sha512(w, h, context);
	i = 0;
	while (i < 80)
	{
		sha512_dgst(w, h, i);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		context->words[i] += h[i];
		i++;
	}
}
