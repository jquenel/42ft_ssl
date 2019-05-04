#include <stdlib.h>
#include "ssl_dgst.h"

void	ssl_dgst64_del(t_dgst64 *context)
{
	free(context->buf);
	free(context->words);
	free(context);
}
