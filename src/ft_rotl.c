#include <stdint.h>
#include "ft_ssl.h"

uint32_t		ft_rotl32(uint32_t word, uint32_t shift)
{
	return ((word << shift) | (word >> (32 - shift)));
}

uint64_t		ft_rotl64(uint64_t word, uint64_t shift)
{
	return ((word << shift) | (word >> (64 - shift)));
}
