#include <unistd.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"

static int	pad(t_dgst64 *context, int count, int ispadding)
{
	if (!ispadding)
	{
		context->buf[count] = 0x80;
		count++;
	}
	ft_bzero(&(context->buf[count]), 112 - count);
	ssl_sha2_encode128(context->flen, &(context->buf[112]));
	return (-1);
}

static int	read_from_x(t_dgst64 *context, char const *src, int i, int fd)
{
	int		count;

	count = 0;
	if (fd == 0)
	{
		count = ft_read_stdin((char *)context->buf, 128);
		if ((context->flags & DGST_FLAG_STDIN) && !(isatty(0)))
			write(1, context->buf, count);
		return (count);
	}
	else if (fd > 0)
		return read(fd, context->buf, 128);
	else
	{
		if (!src)
			return (-1);
		while (count < 128 && src[i + count])
		{
			context->buf[count] = src[i + count];
			count++;
		}
		return (count);
	}
}

int			ssl_dgst64_fillbuf(t_dgst64 *context, char const *src, \
							int i, int fd)
{
	static int	ispadding = 0;
	int			count;

	if (ispadding != 0 && !(ispadding = 0))
		return (pad(context, 0, 1));
	if ((count = read_from_x(context, src, i, fd)) == -1)
		return (-2);
	context->flen += count * 8;
	if (count < 111)
		return (pad(context, count, 0));
	else if (count < 128)
	{
		context->buf[count] = 0x80;
		count++;
		ft_bzero(&(context->buf[count]), 127 - count);
		ispadding = 1;
		return (i + count);
	}
	else
		return (i + count);
}
