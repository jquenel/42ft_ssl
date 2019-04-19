#include "libargc.h"
#include "ft_ssl.h"

static void		ap_usage(t_argparser *aplst)
{
	(void)aplst;
	ft_putstrfd("usage : ft_ssl stuff [more_stuff]\n", 2);
}

int				main(int argc, char const **argv)
{
	t_argparser		*aplst;
	t_parsed		*parsed;

	if (!(aplst = ssl_build_parsers()))
		return (1);
	if (!(parsed = ap_parse(aplst, argc, argv)))
	{
		ap_usage(aplst);
		return (0);
	}
	parsed->f(parsed->args, parsed->flags);
	return (0);
}
