#include "libargc.h"
#include "ft_ssl.h"

static int	ssl_md5_stdin(t_arg *args, int flags)
{
	(void)args;
	return (flags);
}

static int	ssl_md5_strarg(t_arg *args, int flags)
{
	(void)args;
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
	digested += ssl_md5_stdin(args, flags);
	digested += ssl_md5_strarg(args, flags);
	digested += ssl_md5_files(args, flags);
	return (digested);
}
