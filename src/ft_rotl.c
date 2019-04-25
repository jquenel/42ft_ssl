#include <stdint.h>
#include "ft_ssl.h"

uint32_t		ft_rotl32(uint32_t word, uint32_t shift)
{
	return ((word << shift) | (word >> (32 - shift)));
}
