/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_stdin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:20:12 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:20:32 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "ft_ssl.h"

int		ft_read_stdin(char *buf, size_t bufsize)
{
	size_t		i;
	int			n;

	i = 0;
	while (i < bufsize \
			&& (n = read(0, &(buf[i]), bufsize - i)) > 0)
		i += n;
	if (n == -1)
		return (-1);
	return (i);
}
