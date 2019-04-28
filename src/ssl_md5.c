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

static int	ssl_md5_stdin(t_arg *args, int flags, t_md5 *context)
{
	int			i;

	(void)args;
	if (flags & DGST_FLAG_STDIN)
	{
		while ((i = ssl_md5_fillbuf(context, NULL, i, 0)) > -1)
			ssl_md5_update(context);
		if (i == -2)
			return (0);
		ssl_md5_update(context);
		ssl_md5_print(context, flags);
		ssl_md5_reset(context);
	}
	return (1);
}

static int	ssl_md5_strarg(t_arg *args, int flags, t_md5 *context)
{
	t_arg		*cur;
	int			i;

	cur = args;
	while (cur)
	{
		i = 0;
		if (cur->flag & DGST_FLAG_STRARG)
		{
			while ((i = ssl_md5_fillbuf(context, cur->strcnt, i, -1)) > -1)
				ssl_md5_update(context);
			if (i == -2)
				return (0);
			ssl_md5_update(context);
			ssl_md5_print(context, flags);
			ssl_md5_reset(context);
		}
		cur = cur->next;
	}
	return (1);
}

static int	ssl_md5_files(t_arg *args, int flags, t_md5 *context)
{
	t_arg		*cur;
	int			i;
	int			fd;

	cur = args;
	while (cur)
	{
		i = 0;
		if (!cur->flag && cur->strcnt)
		{
			if ((fd = open(cur->strcnt, O_RDONLY)) == -1)
				return (0);
			while ((i = ssl_md5_fillbuf(context, cur->strcnt, i, fd)) > -1)
				ssl_md5_update(context);
			if (i == -2)
				return (0);
			ssl_md5_update(context);
			ssl_md5_print(context, flags);
			ssl_md5_reset(context);
			close(fd);
		}
		cur = cur->next;
	}
	return (1);
}

int			ssl_md5(t_arg *args, int flags)
{
	int		digested;
	t_md5	*context;

	if (!(context = ssl_md5_init()))
		return (0);
	digested = 0;
	if (flags & DGST_FLAG_STDIN)
		digested += ssl_md5_stdin(args, flags, context);
	ssl_md5_reset(context);
	if (flags & DGST_FLAG_STRARG)
		digested += ssl_md5_strarg(args, flags, context);
	ssl_md5_reset(context);
	digested += ssl_md5_files(args, flags, context);
	ssl_md5_del(context);
	return (digested);
}
