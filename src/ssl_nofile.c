/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_nofile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:33:56 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:33:58 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		ssl_nofile(char const *app, char const *filename)
{
	ft_putstr("ft_ssl: ");
	ft_putstr(app);
	ft_putstr(filename);
	ft_putchar(':');
	ft_putstr(" No such file or directory\n");
}
