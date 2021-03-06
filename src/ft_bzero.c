/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:07:03 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 21:04:18 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		((char *)s)[n] = 0;
}
