# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 19:17:54 by yenyilma          #+#    #+#              #
#    Updated: 2024/12/04 18:30:27 by yenyilma         ###   ########.fr        #
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
SRC = push_swap.c data_parser.c ft_lstsort.c ft_stackclear.c ft_stacknew.c ft_stackpop.c \
	ft_stackpush.c help.c operation.c push_operations.c r_rotate_operations.c rotate_operations.c \
	stack_help.c swap_operations.c target.c transaction.c 
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(PRINTF) $(OBJ) $(HEADER) 
	@$(CC) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
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