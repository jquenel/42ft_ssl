#include <unistd.h>
#include "ft_ssl.h"

int		ft_putstr(char const *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (write(1, str, i));
}
