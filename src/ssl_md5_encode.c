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
