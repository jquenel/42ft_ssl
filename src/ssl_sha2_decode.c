#include <stdint.h>
#include "ssl_dgst.h"

uint32_t		ssl_sha2_decode32(unsigned char *input)
{
	return (((uint32_t)input[3] & 0xff)
				| (((uint32_t)input[2] & 0xff) << 8)
				| (((uint32_t)input[1] & 0xff) << 16)
				| (((uint32_t)input[0] & 0xff) << 24));
}

uint64_t		ssl_sha2_decode64(unsigned char *input)
{
	return (((uint64_t)input[7] & 0xff)
			| (((uint64_t)input[6] & 0xff) << 8)
			| (((uint64_t)input[5] & 0xff) << 16)
			| (((uint64_t)input[4] & 0xff) << 24)
			| (((uint64_t)input[3] & 0xff) << 32)
			| (((uint64_t)input[2] & 0xff) << 40)
			| (((uint64_t)input[1] & 0xff) << 48)
			| (((uint64_t)input[0] & 0xff) << 56));
}
