#include <stdlib.h>
#include <stdint.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"

t_dgst64			*ssl_dgst64_init(size_t hashlen, int flags)
{
	t_dgst64		*context;

	if (!(context = (t_dgst64 *)malloc(sizeof(t_dgst64))))
		return (NULL);
	if (!(context->buf = (unsigned char *)malloc(sizeof(unsigned char) * 128)))
		return (NULL);
	if (!(context->words = (uint64_t *)malloc(sizeof(uint64_t) * hashlen)))
		return (NULL);
	context->flen = 0;
	ft_bzero(context->buf, sizeof(char) * 128);
	context->flags = flags;
	context->hashlen = hashlen;
	return (context);
}
