#include <stdint.h>
#include "ft_ssl.h"

uint32_t		ssl_sha2_decode(unsigned char *input)
{
	return (((uint32_t)input[3] & 0xff)
				| (((uint32_t)input[2] & 0xff) << 8)
				| (((uint32_t)input[1] & 0xff) << 16)
				| (((uint32_t)input[0] & 0xff) << 24));
}
