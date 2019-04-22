#include "libargc.h"
#include "ft_ssl.h"
#include "ssl_dgst.h"

static int	ssl_md5_stdin(t_arg *args, int flags)
{
	(void)args;
	return (flags);
}

static int	ssl_md5_strarg(t_arg *args, int flags)
{
	t_md5		*context;
	t_arg		*cur;
	int			i;

	if (!(context = ssl_md5_init()))
		return (0);
	cur = args;
	while (cur)
	{
		i = 0;
		if (cur->flag & DGST_FLAG_STDIN)
		{
			while ((i = ssl_md5_fillbuf(context, args->strcnt, i, -1)) != -1)
				ssl_md5_update(context);
		}
		cur = cur->next;
	}
	ssl_md5_del(context);
	return (flags);
}

static int	ssl_md5_files(t_arg *args, int flags)
{
	(void)args;
	return (flags);
}

int			ssl_md5(t_arg *args, int flags)
{
	int		digested;

	digested = 0;
	if (flags & DGST_FLAG_STDIN)
		digested += ssl_md5_stdin(args, flags);
	if (flags & DGST_FLAG_STRARG)
		digested += ssl_md5_strarg(args, flags);
	digested += ssl_md5_files(args, flags);
	return (digested);
}
