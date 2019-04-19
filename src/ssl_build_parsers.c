#include "libargc.h"
#include "ft_ssl.h"

t_argparser		*ssl_build_parsers(void)
{
	t_argparser		*aplst;
	t_argparser		*parser;
	
	aplst = NULL;
	if (!(parser = ssl_dgst_parsers()))
		return (NULL);
	aplst = ap_pushb(aplst, parser);
	return (aplst);
}
