NAME=		ft_ssl

##
##		RESSOURCES
##

SRC_PATH=	src

OBJ_PATH=	obj

CPPFLAGS=	-Iinclude -Ilibargc/include

SRC_NAME=	ft_ssl.c\
			ft_ssl_usage.c\
			ssl_build_parsers.c\
			ssl_dgst_parsers.c\
			ssl_cipher_parsers.c\
			ssl_nofile.c\
			\
			ssl_dgst_const.c\
			ssl_dgst32_init.c\
			ssl_dgst32_del.c\
			ssl_dgst32_fillbuf.c\
			ssl_dgst64_init.c\
			ssl_dgst64_del.c\
			ssl_dgst64_fillbuf.c\
			ssl_md5.c\
			ssl_md5.c\
			ssl_md5_encode.c\
			ssl_md5_decode.c\
			ssl_md5_update.c\
			ssl_md5_print.c\
			ssl_sha224.c\
			ssl_sha256.c\
			ssl_sha384.c\
			ssl_sha512.c\
			ssl_sha2_encode.c\
			ssl_sha2_decode.c\
			ssl_sha256_update.c\
			ssl_sha512_update.c\
			ssl_sha224_print.c\
			ssl_sha256_print.c\
			ssl_sha384_print.c\
			ssl_sha512_print.c\
			\
			ssl_base64.c\
			\
			ft_putchar.c\
			ft_putchar_hex.c\
			ft_putstr.c\
			ft_read_stdin.c\
			ft_rotl.c\
			ft_rotr.c\
			ft_bzero.c\
			ft_endian.c\
			\

SRC=		$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ=		$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_NAME=	$(SRC_NAME:.c=.o)

##
##		COMPILER FLAGS
##

CFLAGS=		-Wextra -Wall -Werror -g -fsanitize=address

CC=			gcc

LDFLAGS=	-Llibargc

LIBS=		-largc

LDLIBS=		$(LDFLAGS) $(LIBS)

##
##		Compile using the program's name to recompile that program.
##		Compile with test for special testing purposes.
##

all:			clibs $(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDLIBS)
				@echo "compiled $@."

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
				@mkdir $(OBJ_PATH) 2> /dev/null || true
				$(CC) $(CFLAGS) -o $@ -c $< $(CPPFLAGS)

clibs:			
				@make -C libargc

##
##		Use fclean to clean this program.
##

clean:
				@rm -Rf $(OBJ_PATH)
				@echo "clean"

fclean:			clean
				@rm -f $(NAME)
				@echo "fclean"

lclean:			fclean
				@make -C libargc fclean

re:				fclean all

lre:			lclean all

.PHONY:			all clean fclean re lclean lre
