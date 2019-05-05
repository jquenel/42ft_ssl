/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_dgst64_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:22:00 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:22:01 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ssl_dgst.h"

void	ssl_dgst64_del(t_dgst64 *context)
{
	free(context->buf);
	free(context->words);
	free(context);
}
