#include "libargc.h"
#include "ft_ssl.h"

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

static t_argparser	*ssl_sha256_parser(void)
{
	t_argparser		*parser;

	if (!(parser = ap_new("sha256", ssl_sha256)))
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

t_argparser			*ssl_dgst_parsers(void)
{
	t_argparser		*apdgst;
	t_argparser		*parser;

	apdgst = NULL;
	if (!(parser = ssl_md5_parser()))
		return (NULL);
	apdgst = ap_pushb(apdgst, parser);
	if (!(parser = ssl_sha256_parser()))
	{
		ap_del(apdgst);
		return (NULL);
	}
	apdgst = ap_pushb(apdgst, parser);
	return (apdgst);
}
