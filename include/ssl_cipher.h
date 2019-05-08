/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_cipher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:20:42 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/08 18:23:03 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_CIPHER_H
# define SSL_CIPHER_H

# include <stdint.h>
# include "ft_ssl.h"
# include "libargc.h"

int			ssl_base64(t_arg *args, int flags);

#endif
