#include <stdint.h>
#include <unistd.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"

static void		print_dgst(t_dgst32 *context)
{
	int			i;
	int			j;

	i = 0;
	while (i < 7)
	{
		j = 3;
		while (j >= 0)
		{
			ft_putchar_hex(((char *)&(context->words[i]))[j]);
			j--;
		}
		i++;
	}
}

static void		print_filenamefront(char *fname, int argflag)
{
	ft_putstr("SHA224(");
	if (argflag & FLAG_STR)
	   ft_putchar('"');	
	if (fname)
		ft_putstr(fname);
	else
		ft_putstr("STDIN");
	if (argflag & FLAG_STR)
	   ft_putchar('"');	
	ft_putstr(")= ");
}

static void		print_filenameback(char *fname, int argflag)
{
	ft_putstr(" ");
	if (argflag & FLAG_STR)
	   ft_putchar('"');	
	if (fname)
		ft_putstr(fname);
	else
		ft_putstr("STDIN");
	if (argflag & FLAG_STR)
	   ft_putchar('"');	
}

void			ssl_sha224_print(t_dgst32 *context, char *fname, \
							int argflag, int *flags)
{
	if (*flags & DGST_FLAG_PLN) 
	{
		*flags = (*flags & DGST_FLAG_PLN) ^ DGST_FLAG_PLN;
		ft_putchar('\n');
	}
	if (!(*flags & (DGST_FLAG_QUIET | DGST_FLAG_REV)))
		print_filenamefront(fname, argflag);
	print_dgst(context);
	if (!(*flags & DGST_FLAG_QUIET) && (*flags & DGST_FLAG_REV))
		print_filenameback(fname, argflag);
	ft_putchar('\n');
}
