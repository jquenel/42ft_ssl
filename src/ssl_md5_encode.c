#include <stdint.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"

static void	encode_little_endian(uint32_t n, unsigned char *s)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		s[i] = ((unsigned char *)&n)[3 - i];
		i++;
	}
}

static void	encode_big_endian(uint32_t n, unsigned char *s)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		s[i] = ((unsigned char *)&n)[i];
		i++;
	}
}

void		ssl_md5_encode(uint32_t n, unsigned char *s, int endian)
{
	if (endian)
	{
		s[0] = (unsigned char)(n & 0xff);
		s[1] = (unsigned char)((n >> 8) & 0xff);
		s[2] = (unsigned char)((n >> 16) & 0xff);
		s[3] = (unsigned char)((n >> 24) & 0xff);
		return;
	}
	if (endian == LITTLE_ENDIAN)
		encode_little_endian(n, s);
	else
		encode_big_endian(n, s);
}
