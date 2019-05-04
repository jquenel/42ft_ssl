#include "ft_ssl.h"

void		ft_putchar_hex(char c)
{
	static char	*hextable = "0123456789abcdef";
	
	ft_putchar(hextable[(c >> 4) & 0xf]);
	ft_putchar(hextable[c & 0xf]);
}
