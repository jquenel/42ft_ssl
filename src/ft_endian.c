#include "ft_ssl.h"

int		ft_endian(void)
{
	int		i;
	char	*s;

	i = 1;
	s = (char *)&i;
	if (s[0] == 1)
		return (LITTLE_ENDIAN);
	else
		return (BIG_ENDIAN);
}
