/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_cipher_parsers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:23:54 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/08 18:27:42 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "libargc.h"
#include "ssl_cipher.h"

static t_argparser	*ssl_base64_parser(void)
{
	t_argparser		*parser;

	if (!(parser = ap_new("base64", ssl_base64)))
		return (NULL);
	if (!ap_addrule(parser, 'i', T_STR))
		return (NULL);
	if (!ap_addrule(parser, 'o', T_STR))
		return (NULL);
	if (!ap_addrule(parser, 'e', T_NO))
		return (NULL);
	if (!ap_addrule(parser, 'd', T_NO))
		return (NULL);
	return (parser);
}

t_argparser			*ssl_cipher_parsers(void)
{
	t_argparser		*apdgst;
	t_argparser		*base64_parser;

	apdgst = NULL;
	if (!(base64_parser = ssl_base64_parser()))
		return (NULL);
	apdgst = ap_pushb(apdgst, base64_parser);
	return (apdgst);
}
