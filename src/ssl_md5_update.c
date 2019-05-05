/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_md5_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:27:58 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/05 23:41:22 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_ssl.h"
#include "ssl_dgst.h"
#include "ssl_dgst_const.h"

static void	step_one(t_dgst32 *context, uint32_t dw[4])
{
	uint32_t	f;
	int			i;
	int			g;

	i = 0;
	while (i < 16)
	{
		f = ((dw[1]) & (dw[2])) | ((~dw[1]) & (dw[3]));
		g = i;
		f = f + dw[0] + g_md5_k[i] + ssl_md5_decode(&(context->buf[g * 4]));
		dw[0] = dw[3];
		dw[3] = dw[2];
		dw[2] = dw[1];
		dw[1] = dw[1] + ft_rotl32(f, g_md5_s[i]);
		i++;
	}
}

static void	step_two(t_dgst32 *context, uint32_t dw[4])
{
	uint32_t	f;
	int			i;
	int			g;

	i = 16;
	while (i < 32)
	{
		f = ((dw[1] & dw[3]) | (dw[2] & (~dw[3])));
		g = (5 * i + 1) % 16;
		f = f + dw[0] + g_md5_k[i] + ssl_md5_decode(&(context->buf[g * 4]));
		dw[0] = dw[3];
		dw[3] = dw[2];
		dw[2] = dw[1];
		dw[1] = dw[1] + ft_rotl32(f, g_md5_s[i]);
		i++;
	}
}

static void	step_three(t_dgst32 *context, uint32_t dw[4])
{
	uint32_t	f;
	int			i;
	int			g;

	i = 32;
	while (i < 48)
	{
		f = (dw[1] ^ dw[2] ^ dw[3]);
		g = (3 * i + 5) % 16;
		f = f + dw[0] + g_md5_k[i] + ssl_md5_decode(&(context->buf[g * 4]));
		dw[0] = dw[3];
		dw[3] = dw[2];
		dw[2] = dw[1];
		dw[1] = dw[1] + ft_rotl32(f, g_md5_s[i]);
		i++;
	}
}

static void	step_four(t_dgst32 *context, uint32_t dw[4])
{
	uint32_t	f;
	int			i;
	int			g;

	i = 48;
	while (i < 64)
	{
		f = (dw[2] ^ (dw[1] | (~dw[3])));
		g = (7 * i) % 16;
		f = f + dw[0] + g_md5_k[i] + ssl_md5_decode(&(context->buf[g * 4]));
		dw[0] = dw[3];
		dw[3] = dw[2];
		dw[2] = dw[1];
		dw[1] = dw[1] + ft_rotl32(f, g_md5_s[i]);
		i++;
	}
}

void		ssl_md5_update(t_dgst32 *context)
{
	uint32_t	dw[4];

	dw[0] = context->words[0];
	dw[1] = context->words[1];
	dw[2] = context->words[2];
	dw[3] = context->words[3];
	step_one(context, dw);
	step_two(context, dw);
	step_three(context, dw);
	step_four(context, dw);
	context->words[0] += dw[0];
	context->words[1] += dw[1];
	context->words[2] += dw[2];
	context->words[3] += dw[3];
}
