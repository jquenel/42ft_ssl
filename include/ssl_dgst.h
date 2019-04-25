#ifndef SSL_DGST_H
# define SSL_DGST_H

#include <stdint.h>
#include "libargc.h"

# define DGST_FLAG_STDIN	FLAG_P
# define DGST_FLAG_STRARG	FLAG_S
# define DGST_FLAG_QUIET	FLAG_Q
# define DGST_FLAG_REV		FLAG_R

typedef struct			s_md5
{
	uint64_t		flen;
	int				endian;
	uint32_t		*words;
	unsigned char	*buf;
}						t_md5;

int				ssl_md5(t_arg *args, int flags);
t_md5			*ssl_md5_init(void);
void			ssl_md5_del(t_md5 *context);
uint32_t		ssl_md5_decode(unsigned char *input, int endian);
void			ssl_md5_encode(uint32_t n, unsigned char *s, int endian);
int				ssl_md5_fillbuf(t_md5 *context, char const *src, int i, int fd);
void			ssl_md5_update(t_md5 *context);
void			ssl_md5_print(t_md5 *context, int flags);


int				ssl_sha256(t_arg *args, int flags);

#endif
