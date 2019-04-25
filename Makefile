NAME=		ft_ssl

##
##		RESSOURCES
##

SRC_PATH=	src

OBJ_PATH=	obj

CPPFLAGS=	-Iinclude -Ilibargc/include

SRC_NAME=	ft_ssl.c\
			ssl_build_parsers.c\
			ssl_dgst_parsers.c\
			\
			ssl_dgst_const.c\
			ssl_md5.c\
			ssl_md5_init.c\
			ssl_md5_del.c\
			ssl_md5_encode.c\
			ssl_md5_decode.c\
			ssl_md5_fillbuf.c\
			ssl_md5_update.c\
			ssl_md5_print.c\
			ssl_sha256.c\
			\
			ft_putchar.c\
			ft_rotl.c\
			ft_bzero.c\
			ft_endian.c\
			\

SRC=		$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ=		$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_NAME=	$(SRC_NAME:.c=.o)

##
##		COMPILER FLAGS
##

CFLAGS=		-Wextra -Wall -Werror #-g -fsanitize=address

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
