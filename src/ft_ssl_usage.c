/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_usage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 20:33:14 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/07 20:37:09 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		standard_usage(void)
{
	ft_putstr("\nStandard commands:\n");
}

static void		dgst_usage(void)
{
	ft_putstr("\nMessage digest commands:\n");
	ft_putstr("md5\n");
	ft_putstr("sha224\n");
	ft_putstr("sha256\n");
	ft_putstr("sha384\n");
	ft_putstr("sha512\n");
}

static void		cipher_usage(void)
{
	ft_putstr("\nCipher commands:\n");
}

void		ft_ssl_usage(void)
{
	ft_putstr("usage : ft_ssl command [options] [files]\n");
	standard_usage();
	dgst_usage();
	cipher_usage();
}
