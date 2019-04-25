
#include <stdint.h>
#include "ssl_dgst.h"

uint32_t		ssl_md5_f(uint32_t b, uint32_t c, uint32_t d)
{
	return ((b & c) | (~b & d));
}

uint32_t		ssl_md5_g(uint32_t b, uint32_t c, uint32_t d)
{
	return ((b & d) | (c & ~d));
}

uint32_t		ssl_md5_h(uint32_t b, uint32_t c, uint32_t d)
{
	return (b ^ c ^ d);
}

uint32_t		ssl_md5_i(uint32_t b, uint32_t c, uint32_t d)
{
	return (c ^ (b | ~d));
}
