#include <stdint.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"

void		ssl_md5_encode(uint32_t n, unsigned char *s)
{
	s[0] = (unsigned char)(n & 0xff);
	s[1] = (unsigned char)((n >> 8) & 0xff);
	s[2] = (unsigned char)((n >> 16) & 0xff);
	s[3] = (unsigned char)((n >> 24) & 0xff);
}
