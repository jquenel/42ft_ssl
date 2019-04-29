#include "libargc.h"
#include "ft_ssl.h"
#include "ssl_dgst.h"

static t_argparser	*ssl_md5_parser(void)
{
	t_argparser		*parser;

	if (!(parser = ap_new("md5", ssl_md5)))
		return (NULL);
	if (!ap_addrule(parser, 'p', T_NO))
		return (NULL);
	if (!ap_addrule(parser, 'q', T_NO))
		return (NULL);
	if (!ap_addrule(parser, 'r', T_NO))
		return (NULL);
	if (!ap_addrule(parser, 's', T_STR))
		return (NULL);
	return (parser);
}

static t_argparser	*ssl_sha2_parsers(t_argparser *model)
{
	char		*keys[4] = {"sha256", "sha384", "sha512", NULL};
	t_pfunc		funcs[4] = {ssl_sha256, ssl_sha384, ssl_sha512, NULL};
	int			i;
	t_argparser	*sha2_parsers;
	t_argparser	*parser;

	sha2_parsers = NULL;
	i = 0;
	while (keys[i])
	{
		if (!(parser = ap_duplicate(model, keys[i], funcs[i])))
		{
			if (sha2_parsers)
				ap_del(sha2_parsers);
			return (NULL);
		}
		sha2_parsers = ap_pushb(sha2_parsers, parser);
		i++;
	}
	return (sha2_parsers);
}

t_argparser			*ssl_dgst_parsers(void)
{
	t_argparser		*apdgst;
	t_argparser		*md5_parser;
	t_argparser		*sha2_parsers;

	apdgst = NULL;
	if (!(md5_parser = ssl_md5_parser()))
		return (NULL);
	apdgst = ap_pushb(apdgst, md5_parser);
	if (!(sha2_parsers = ssl_sha2_parsers(md5_parser)))
	{
		ap_del(apdgst);
		return (NULL);
	}
	apdgst = ap_pushb(apdgst, sha2_parsers);
	return (apdgst);
}
