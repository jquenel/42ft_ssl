#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libargc.h"
#include "ft_ssl.h"
#include "ssl_dgst.h"

static void	ssl_sha384_reset(t_dgst64 *context)
{
	ft_bzero(context->buf, 128);
	context->flen = 0;
	context->words[0] = 0xcbbb9d5dc1059ed8;
	context->words[1] = 0x629a292a367cd507;
	context->words[2] = 0x9159015a3070dd17;
	context->words[3] = 0x152fecd8f70e5939;
	context->words[4] = 0x67332667ffc00b31;
	context->words[5] = 0x8eb44a8768581511;
	context->words[6] = 0xdb0c2e0d64f98fa7;
	context->words[7] = 0x47b5481dbefa4fa4;
}

static int	sha384_run(t_dgst64 *context, int fd, t_arg *arg, int *flags)
{
	int				i;
	char			*fname;

	fname = arg ? (char *)arg->strcnt : NULL;
	ssl_sha384_reset(context);
	i = 0;
	while ((i = ssl_dgst64_fillbuf(context, fname, i, fd)) > -1)
		ssl_sha512_update(context);
	if (i == -2)
		return (i);
	ssl_sha512_update(context);
	ssl_sha384_print(context, fname, flags);
	return (i);
}

int			ssl_sha384(t_arg *args, int flags)
{
	t_dgst64	*context;
	int			fd;

	if (!(context = ssl_dgst64_init(SHA2_HASHLEN, flags)))
		return (0);
	if (flags & (DGST_FLAG_STDIN | DGST_FLAG_NOARG))
		sha384_run(context, 0, args, &flags);
	while (args)
	{
		if (args->flag & DGST_FLAG_STRARG)
			sha384_run(context, -1, args, &flags);
		else if (!args->flag && args->strcnt)
		{
			if ((fd = open(args->strcnt, O_RDONLY)) == -1)
				ssl_nofile("sha384: ", args->strcnt); 
			else
			{
				sha384_run(context, fd, args, &flags);
				close(fd);
			}
		}
		args = args->next;
	}
	ssl_dgst64_del(context);
	return (1);
}
