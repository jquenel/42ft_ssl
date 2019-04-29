#include "libargc.h"
#include "ft_ssl.h"

static void		ap_usage(t_argparser *aplst)
{
	(void)aplst;
	ft_putstr("usage : ft_ssl md5 [options]\n");
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
	if (!parsed->args)
		parsed->flags |= FT_SSL_NOARG;
	parsed->f(parsed->args, parsed->flags);
	ap_del(aplst);
	parseddel(parsed);
	return (0);
}
