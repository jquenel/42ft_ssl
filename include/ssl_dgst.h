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
	uint32_t		buf[16];
	uint32_t		words[4];
	uint64_t		flen;
	uint32_t		*k;
	uint32_t		*s;	
}						t_md5;

int		ssl_md5(t_arg *args, int flags);
int		ssl_md5_fillbuf(t_md5 *context, char const *src, int i, int fd);
void	ssl_md5_update(t_md5 *context);
t_md5	*ssl_md5_init(void);
void	ssl_md5_del(t_md5 *context);

int		ssl_sha256(t_arg *args, int flags);

#endif
