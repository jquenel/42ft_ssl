#include "ft_ssl.h"

void		ssl_nofile(char const *app, char const *filename)
{
	ft_putstr("ft_ssl: ");
	ft_putstr(app);
	ft_putstr(filename);
	ft_putchar(':');
	ft_putstr(" No such file or directory\n");
}
