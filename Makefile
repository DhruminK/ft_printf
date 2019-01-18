# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 14:25:44 by dkhatri           #+#    #+#              #
#    Updated: 2019/01/18 17:54:40 by dkhatri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MAIN = main.c

FLAGS = 

LIBFTDIR = ./libft/

MANDATORY = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
			ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c

ADDITIONAL = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
			 ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
			 ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
			 ft_strarrdel.c ft_strarrdup.c ft_strndup.c \
			 ft_strarrnew.c ft_strcnt.c ft_strchrjoin.c

DISPLAY = ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
		  ft_putnbr_fd.c ft_putchar.c ft_putchar_fd.c

BONUS = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		ft_lstmap.c ft_lstaddlast.c ft_lstfindsize.c

SRCDIR = ./src/

CONV = ft_conversions.c ft_int_conv.c

HELPER = ft_helper.c ft_itoa.c ft_uitoa_base.c

PARSOR = ft_parsor.c



SRCO = $(addprefix $(SRCDIR), $(CONV:.c=.o)) \
		$(addprefix $(SRCDIR), $(HELPER:.c=.o)) \
		$(addprefix $(SRCDIR), $(PARSOR:.c=.o)) \
		$(addprefix $(LIBFTDIR), $(MANDATORY:.c=.o)) \
		$(addprefix $(LIBFTDIR), $(ADDITIONAL:.c=.o)) \
		$(addprefix $(LIBFTDIR), $(BONUS:.c=.o)) \
		$(addprefix $(LIBFTDIR), $(DISPLAY:.c=.o))

DEPS = ./includes/ft_printf.h ./libft/libft.h

%.o: %.c $(DEPS)
	gcc $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(SRCO)
	ar -rc $(NAME) $(SRCO)
	ranlib $(NAME)

test: all
	gcc -o printf $(SRCO) main.c -lftprintf -L.

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
