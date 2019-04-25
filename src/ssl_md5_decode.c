#include <stdint.h>
#include "ft_ssl.h"

static uint32_t	decode_little_endian(char *input)
{
	uint32_t	n;
	int			i;

	i = 0;
	while (i < 4)
	{
		((char *)&n)[i] = input[i];
		i++;
	}
	return (n);
}

static uint32_t	decode_big_endian(char *input)
{
	uint32_t	n;
	int			i;

	i = 0;
	while (i < 4)
	{
		((char *)&n)[i] = input[3 - i];
		i++;
	}
	return (n);
}

uint32_t		ssl_md5_decode(char *input, int endian)
{
	uint32_t	n;
	if (endian)
	{
	   n  = (((uint32_t)input[0] & 0xff)
				| (((uint32_t)input[1] & 0xff) << 8)
				| (((uint32_t)input[2] & 0xff) << 16)
				| (((uint32_t)input[3] & 0xff) << 24));
	   //printf("decoding : %x\n", n);
	   return (n);
	}
	if (endian == LITTLE_ENDIAN)
		return (decode_little_endian(input));
	else
		return (decode_big_endian(input));
}
