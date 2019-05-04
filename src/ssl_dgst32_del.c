#include <stdlib.h>
#include "ssl_dgst.h"

void	ssl_dgst32_del(t_dgst32 *context)
{
	free(context->buf);
	free(context->words);
	free(context);
}
