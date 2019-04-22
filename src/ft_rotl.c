#include <stdint.h>
#include <assert.h>
#include "ft_ssl.h"

uint32_t		ft_rotl32(uint32_t word, uint32_t shift)
{
	assert(shift < 32);
	return ((word << shift) | (word >> ((-shift) & 31)));
}
