/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_dgst32_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:21:23 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:21:24 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ssl_dgst.h"

void	ssl_dgst32_del(t_dgst32 *context)
{
	free(context->buf);
	free(context->words);
	free(context);
}
