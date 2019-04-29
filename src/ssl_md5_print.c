#include <stdint.h>
#include <unistd.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"

static void		print_hex_char(char c)
{
	static char	*hextable = "0123456789abcdef";
	
	ft_putchar(hextable[(c >> 4) & 0xf]);
	ft_putchar(hextable[c & 0xf]);
}

void			ssl_md5_print(t_md5 *context, char *fname, int flags)
{
	int			i;
	int			j;

	i = 0;
	if (isatty(0))
		ft_putchar('\n');
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			print_hex_char(((char *)&(context->words[i]))[j]);
			j++;
		}
		i++;
	}
	ft_putchar('\n');
	if (!(flags & DGST_FLAG_QUIET) && fname)
	{
		ft_putstr(fname);
		ft_putchar('\n');
	}
}
