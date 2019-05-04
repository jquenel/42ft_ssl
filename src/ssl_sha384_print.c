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

void			ssl_sha384_print(t_dgst64 *context, char *fname, int *flags)
{
	int			i;
	int			j;

	if (*flags & DGST_FLAG_PLN) 
	{
		*flags = (*flags & DGST_FLAG_PLN) ^ DGST_FLAG_PLN;
		ft_putchar('\n');
	}
	while (i < 6)
	{
		j = 7;
		while (j >= 0)
		{
			print_hex_char(((char *)&(context->words[i]))[j]);
			j--;
		}
		i++;
	}
	if (!(*flags & DGST_FLAG_QUIET))
	{
		ft_putstr(" - ");
		if (fname)
			ft_putstr(fname);
	}
	ft_putchar('\n');
}