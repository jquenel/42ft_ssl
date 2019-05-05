/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_build_parsers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:20:54 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:20:58 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
