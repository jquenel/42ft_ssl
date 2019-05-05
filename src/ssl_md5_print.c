/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_md5_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:33:04 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:33:48 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"

static void		print_dgst(t_dgst32 *context)
{
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar_hex(((char *)&(context->words[i]))[j]);
			j++;
		}
		i++;
	}
}

static void		print_filenamefront(char *fname, int argflag)
{
	ft_putstr("MD5(");
	if (argflag & FLAG_STR)
		ft_putchar('"');
	if (fname)
		ft_putstr(fname);
	else
		ft_putstr("STDIN");
	if (argflag & FLAG_STR)
		ft_putchar('"');
	ft_putstr(") = ");
}

static void		print_filenameback(char *fname, int argflag)
{
	ft_putstr(" ");
	if (argflag & FLAG_STR)
		ft_putchar('"');
	if (fname)
		ft_putstr(fname);
	else
		ft_putstr("STDIN");
	if (argflag & FLAG_STR)
		ft_putchar('"');
}

void			ssl_md5_print(t_dgst32 *context, char *fname,
							int argflag, int *flags)
{
	if (*flags & DGST_FLAG_PLN)
	{
		*flags = (*flags & DGST_FLAG_PLN) ^ DGST_FLAG_PLN;
		ft_putchar('\n');
	}
	if (!(*flags & DGST_FLAG_QUIET) && !(*flags & DGST_FLAG_REV))
		print_filenamefront(fname, argflag);
	print_dgst(context);
	if (!(*flags & DGST_FLAG_QUIET) && (*flags & DGST_FLAG_REV))
		print_filenameback(fname, argflag);
	ft_putchar('\n');
}
