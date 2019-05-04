#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libargc.h"
#include "ft_ssl.h"
#include "ssl_dgst.h"

static void	ssl_sha512_reset(t_dgst64 *context)
{
	ft_bzero(context->buf, 128);
	context->flen = 0;
	context->words[0] = 0x6a09e667f3bcc908;
	context->words[1] = 0xbb67ae8584caa73b;
	context->words[2] = 0x3c6ef372fe94f82b;
	context->words[3] = 0xa54ff53a5f1d36f1;
	context->words[4] = 0x510e527fade682d1;
	context->words[5] = 0x9b05688c2b3e6c1f;
	context->words[6] = 0x1f83d9abfb41bd6b;
	context->words[7] = 0x5be0cd19137e2179;
}

static int	sha512_run(t_dgst64 *context, int fd, t_arg *arg, int *flags)
{
	int				i;
	char			*fname;

	fname = arg ? (char *)arg->strcnt : NULL;
	ssl_sha512_reset(context);
	i = 0;
	while ((i = ssl_dgst64_fillbuf(context, fname, i, fd)) > -1)
		ssl_sha512_update(context);
	if (i == -2)
		return (i);
	ssl_sha512_update(context);
	ssl_sha512_print(context, fname, flags);
	return (i);
}

int			ssl_sha512(t_arg *args, int flags)
{
	t_dgst64	*context;
	int			fd;

	if (!(context = ssl_dgst64_init(SHA2_HASHLEN, flags)))
		return (0);
	if (flags & (DGST_FLAG_STDIN | DGST_FLAG_NOARG))
		sha512_run(context, 0, args, &flags);
	while (args)
	{
		if (args->flag & DGST_FLAG_STRARG)
			sha512_run(context, -1, args, &flags);
		else if (!args->flag && args->strcnt)
		{
			if ((fd = open(args->strcnt, O_RDONLY)) == -1)
				ssl_nofile("sha512: ", args->strcnt); 
			else
			{
				sha512_run(context, fd, args, &flags);
				close(fd);
			}
		}
		args = args->next;
	}
	ssl_dgst64_del(context);
	return (1);
}
