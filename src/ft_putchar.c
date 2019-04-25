#include <unistd.h>
#include "ft_ssl.h"

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}
