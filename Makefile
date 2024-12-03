# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 19:17:54 by yenyilma          #+#    #+#              #
#    Updated: 2024/11/30 20:13:16 by yenyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h
CC = cc 
FLAGS = -Wall -Werror -Wextzzzz
LIBFT = libft/libft.a
LIBFTDIR = libft
PRINTF = printf/libftprintf.a
PRINTFDIR = printf
SRC = push_swap.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(PRINTF) $(OBJ) $(HEADER) 
	@$(NAME) $(OBJ)
	@echo "compiling..."

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -I $(LIBFTDIR) -I $(PRINTFDIR) -c $< -o $@

$(LIBFT) : $(LIBFTDIR)
	make bonus -C libft

$(LIBFTDIR) :
	git clone git@github.com:theyenerkaan/libft.git libft

$(PRINTF) : $(PRINTFDIR)
	make -C printf

$(PRINTFDIR) :
	git clone git@github.com:theyenerkaan/printf.git printf

update :
	cd libft && git pull

bonus :

clean :
	@rm -rf $(OBJ)
	make clean -C libft
	make clean -C printf

fclean :
	@rm -rf $(OBJ) $(NAME)
	make fclean -C libft
	make fclean -C printf

re : fclean all 