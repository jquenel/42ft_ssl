#include <stdint.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"
#include "ssl_dgst_const.h"

static uint32_t	ch(uint32_t e, uint32_t f, uint32_t g)
{
	return ((e & f) ^ ((~e) & g));
}

static uint32_t	maj(uint32_t a, uint32_t b, uint32_t c)
{
	return ((a & b) ^ (a & c) ^ (b & c));
}

static void		sha256_dgst(uint32_t w[64], uint32_t h[8], int i)
{
	uint32_t	s0;
	uint32_t	s1;
	uint32_t	t0;
	uint32_t	t1;

	s0 = ft_rotr32(h[0], 2) ^ ft_rotr32(h[0], 13) ^ ft_rotr32(h[0], 22);
	s1 = ft_rotr32(h[4], 6) ^ ft_rotr32(h[4], 11) ^ ft_rotr32(h[4], 25);
	t0 = h[7] + s1 + ch(h[4], h[5], h[6]) + sha256_k[i] + w[i]; 
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

static void		prepare_sha256(uint32_t w[64], uint32_t h[8], t_dgst32 *context)
{
	int			i;
	uint32_t	s0;
	uint32_t	s1;

	i = 0;
	while (i < 16)
	{
		w[i] = ssl_sha2_decode32(&(context->buf[i * 4]));
		i++;
	}
	while (i < 64)
	{
		s0 = ft_rotr32(w[i - 15], 7) ^ ft_rotr32(w[i - 15], 18)
			^ (w[i - 15] >> 3);
		s1 = ft_rotr32(w[i - 2], 17) ^ ft_rotr32(w[i - 2], 19)
			^ (w[i - 2] >> 10);
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

void			ssl_sha256_update(t_dgst32 *context)
{
	uint32_t	w[64];
	uint32_t	h[8];
	int			i;
	
	ft_bzero(w, sizeof(uint32_t) * 64);
	prepare_sha256(w, h, context);
	i = 0;
	while (i < 64)
	{
		sha256_dgst(w, h, i);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		context->words[i] += h[i];
		i++;
	}
}
