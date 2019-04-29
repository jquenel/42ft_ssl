#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libargc.h"
#include "ft_ssl.h"
#include "ssl_dgst.h"

static void	ssl_md5_reset(t_md5 *context)
{
	ft_bzero(context->buf, 64);
	context->words[0] = 0x67452301;
	context->words[1] = 0xefcdab89;
	context->words[2] = 0x98badcfe;
	context->words[3] = 0x10325476;
	context->flen = 0;
}

static int	md5_run(t_md5 *context, int fd, t_arg *arg, int flags)
{
	int		i;
	char	*fname;

	fname = arg ? (char *)arg->strcnt : NULL;
	i = 0;
	while ((i = ssl_md5_fillbuf(context, fname, i, fd)) > -1)
		ssl_md5_update(context);
	if (i == -2)
		return (i);
	ssl_md5_update(context);
	ssl_md5_print(context, fname, flags);
	ssl_md5_reset(context);
	return (i);
}

int			ssl_md5(t_arg *args, int flags)
{
	t_md5	*context;
	int		fd;

	if (!(context = ssl_md5_init(flags)))
		return (0);
	if (flags & (DGST_FLAG_STDIN | DGST_FLAG_NOARG))
		md5_run(context, 0, args, flags);
	while (args)
	{
		if (args->flag & DGST_FLAG_STRARG)
			md5_run(context, -1, args, flags);
		else if (!args->flag && args->strcnt)
		{
			if ((fd = open(args->strcnt, O_RDONLY)) == -1)
				ssl_nofile("md5: ", args->strcnt); 
			else
			{
				md5_run(context, fd, args, flags);
				close(fd);
			}
		}
		args = args->next;
	}
	ssl_md5_del(context);
	return (1);
}
