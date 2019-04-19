#ifndef FT_SSL_H
# define FT_SSL_H

t_argparser		*ssl_build_parsers(void);
t_argparser		*ssl_dgst_parsers(void);

int				ssl_md5(t_arg *args, int flags);
int				ssl_sha256(t_arg *args, int flags);

#endif
