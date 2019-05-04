#ifndef SSL_DGST_H
# define SSL_DGST_H

#include <stdint.h>
#include "libargc.h"

# define DGST_FLAG_STDIN	FT_SSL_STDIN
# define DGST_FLAG_STRARG	FT_SSL_STRARG
# define DGST_FLAG_QUIET	FT_SSL_QUIET
# define DGST_FLAG_REV		FT_SSL_REV
# define DGST_FLAG_NOARG	FT_SSL_NOARG
# define DGST_FLAG_PLN		FT_SSL_PLN

# define MD5_HASHLEN		4
# define SHA2_HASHLEN		8

typedef struct			s_dgst32
{
	uint64_t		flen;
	size_t			hashlen;
	int				flags;
	uint32_t		*words;
	unsigned char	*buf;
}						t_dgst32;

typedef struct			s_dgst64
{
	__uint128_t		flen;
	size_t			hashlen;
	int				flags;
	uint64_t		*words;
	unsigned char	*buf;
}						t_dgst64;


t_dgst32		*ssl_dgst32_init(size_t hashlen, int flags);
void			ssl_dgst32_del(t_dgst32 *context);
int				ssl_dgst32_fillbuf(t_dgst32 *context, char const *src, \
									int i, int fd);

t_dgst64		*ssl_dgst64_init(size_t hashlen, int flags);
void			ssl_dgst64_del(t_dgst64 *context);
int				ssl_dgst64_fillbuf(t_dgst64 *context, char const *src, \
									int i, int fd);

int				ssl_md5(t_arg *args, int flags);
uint32_t		ssl_md5_decode(unsigned char *input);
void			ssl_md5_encode(uint32_t n, unsigned char *s);
void			ssl_md5_update(t_dgst32 *context);
void			ssl_md5_print(t_dgst32 *context, char *fname, \
								int argflag, int *flags);

int				ssl_sha224(t_arg *args, int flags);
int				ssl_sha256(t_arg *args, int flags);
int				ssl_sha384(t_arg *args, int flags);
int				ssl_sha512(t_arg *args, int flags);
void			ssl_sha2_encode64(uint64_t n, unsigned char *s);
void			ssl_sha2_encode128(__uint128_t n, unsigned char *s);
uint32_t		ssl_sha2_decode32(unsigned char *input);
uint64_t		ssl_sha2_decode64(unsigned char *input);
void			ssl_sha256_update(t_dgst32 *context);
void			ssl_sha512_update(t_dgst64 *context);
void			ssl_sha224_print(t_dgst32 *context, char *fname, int *flags);
void			ssl_sha256_print(t_dgst32 *context, char *fname, int *flags);
void			ssl_sha384_print(t_dgst64 *context, char *fname, int *flags);
void			ssl_sha512_print(t_dgst64 *context, char *fname, int *flags);

#endif
