/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:22:55 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:23:03 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libargc.h"
#include "ft_ssl.h"

static void		ap_usage(t_argparser *aplst)
{
	(void)aplst;
	ft_putstrfd("usage : ft_ssl stuff [more_stuff]\n", 2);
}

static void		extra_flags(t_parsed *parsed)
{
	if (!parsed->args)
		parsed->flags |= FT_SSL_NOARG;
	if ((parsed->flags & (FT_SSL_NOARG | FT_SSL_STDIN)) && isatty(0))
		parsed->flags |= FT_SSL_PLN;
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
		ap_del(aplst);
		return (0);
	}
	extra_flags(parsed);
	parsed->f(parsed->args, parsed->flags);
	ap_del(aplst);
	parseddel(parsed);
	return (0);
}
