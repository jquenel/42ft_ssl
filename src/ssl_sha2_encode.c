#include <stdint.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"

void		ssl_sha2_encode64(uint64_t n, unsigned char *s)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		s[i] = (unsigned char)((n >> (56 - i * 8)) & 0xff);
		i++;
	}
}

void		ssl_sha2_encode128(__uint128_t n, unsigned char *s)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		s[i] = (unsigned char)((n >> (120 - i * 8)) & 0xff);
		i++;
	}
}
