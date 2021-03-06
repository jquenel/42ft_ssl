/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:46:50 by jquenel           #+#    #+#             */
/*   Updated: 2019/05/08 18:20:19 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdint.h>
# include "libargc.h"

# ifndef BIG_ENDIAN
#  define BIG_ENDIAN		4321
# endif

# ifndef LITTLE_ENDIAN
#  define LITTLE_ENDIAN		1234
# endif

# define FT_SSL_NOARG		FLAG_N
# define FT_SSL_STDIN		FLAG_P
# define FT_SSL_QUIET		FLAG_Q
# define FT_SSL_REV			FLAG_R
# define FT_SSL_STRARG		FLAG_S
# define FT_SSL_PLN			FLAG_27

void			ft_ssl_usage(void);
t_argparser		*ssl_build_parsers(void);
t_argparser		*ssl_dgst_parsers(void);
t_argparser		*ssl_cipher_parsers(void);
void			ssl_nofile(char const *app, char const *filename);

int				ft_read_stdin(char *buf, size_t bufsize);
int				ft_putchar(char c);
void			ft_putchar_hex(char c);
int				ft_putstr(char const *str);
uint32_t		ft_rotl32(uint32_t word, uint32_t n);
uint64_t		ft_rotl64(uint64_t word, uint64_t n);
uint32_t		ft_rotr32(uint32_t word, uint32_t n);
uint64_t		ft_rotr64(uint64_t word, uint64_t n);
void			ft_bzero(void *ptr, size_t n);
int				ft_endian(void);

#endif
