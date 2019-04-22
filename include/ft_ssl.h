#ifndef FT_SSL_H
# define FT_SSL_H

#include <stdint.h>
#include "libargc.h"

t_argparser		*ssl_build_parsers(void);
t_argparser		*ssl_dgst_parsers(void);

uint32_t		ft_rotl(uint32_t word, uint32_t n);
void			ft_bzero(void *ptr, size_t n);

#endif
