#ifndef FT_SSL_H
# define FT_SSL_H

#include <stdint.h>
#include "libargc.h"

#include <stdio.h> //

# ifndef BIG_ENDIAN
#  define BIG_ENDIAN		4321
# endif

# ifndef LITTLE_ENDIAN
#  define LITTLE_ENDIAN		1234
# endif

# define FT_SSL_NOARG		FLAG_N

t_argparser		*ssl_build_parsers(void);
t_argparser		*ssl_dgst_parsers(void);
void			ssl_nofile(char const *app, char const *filename);

int				ft_read_stdin(char *buf, size_t bufsize);
int				ft_putchar(char c);
int				ft_putstr(char const *str);
uint32_t		ft_rotl32(uint32_t word, uint32_t n);
void			ft_bzero(void *ptr, size_t n);
int				ft_endian(void);

#endif
