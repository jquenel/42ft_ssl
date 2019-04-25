/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_md5_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:19:09 by jquenel           #+#    #+#             */
/*   Updated: 2019/04/22 19:19:57 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ssl_dgst.h"

void	ssl_md5_del(t_md5 *context)
{
	free(context->buf);
	free(context->words);
	free(context);
}
