#include <stdlib.h>
#include <stdint.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"

t_dgst32			*ssl_dgst32_init(size_t hashlen, int flags)
{
	t_dgst32		*context;

	if (!(context = (t_dgst32 *)malloc(sizeof(t_dgst32))))
		return (NULL);
	if (!(context->buf = (unsigned char *)malloc(sizeof(unsigned char) * 64)))
		return (NULL);
	if (!(context->words = (uint32_t *)malloc(sizeof(uint32_t) * hashlen)))
		return (NULL);
	context->flen = 0;
	ft_bzero(context->buf, sizeof(char) * 64);
	context->flags = flags;
	context->hashlen = hashlen;
	return (context);
}
