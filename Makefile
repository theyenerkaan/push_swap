# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 19:17:54 by yenyilma          #+#    #+#              #
#    Updated: 2024/12/13 02:46:29 by yenyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CHECKER			=	checker
HEADER			=	push_swap.h
B_HEADER		=	push_swap_bonus.h
CC				=	cc 
FLAGS			=	-Wall -Werror -Wextra 
LIBFT			=	libft/libft.a
LIBFTDIR		=	libft
PRINTF			=	printf/libftprintf.a
PRINTFDIR		=	printf
GNL				=	get_next_line/get_next_line
GNLDIR			=	get_next_line
SRC				=	push_swap.c data_parser.c ft_lstsort.c ft_stackclear.c ft_stacknew.c ft_stackpop.c \
					ft_stackpush.c help.c operation.c push_operations.c r_rotate_operations.c rotate_operations.c \
					stack_help.c swap_operations.c target.c transaction.c

B_SRC			=	checker_bonus.c data_parser_bonus.c ft_lstsort_bonus.c ft_stackclear_bonus.c ft_stacknew_bonus.c \
					ft_stackpop_bonus.c ft_stackpush_bonus.c help_bonus.c operation_bonus.c push_operations_bonus.c r_rotate_operations_bonus.c \
					rotate_operations_bonus.c stack_help_bonus.c swap_operations_bonus.c target_bonus.c transaction_bonus.c ft_strcmp_bonus.c

OBJ				=	$(SRC:.c=.o)
B_OBJ			=	$(B_SRC:.c=.o)

COLOR_RESET 	=	\033[0m
COLOR_GREEN 	=	\033[32m
COLOR_PURPLE 	=	\033[35m
COLOR_YELLOW	=	\033[33m

all : $(NAME)

$(NAME) : $(LIBFT) $(PRINTF) $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "$(COLOR_GREEN)push_swap compiling...$(COLOR_RESET)"

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -I $(LIBFTDIR) -I $(PRINTFDIR) -c $< -o $@

$(LIBFT) : $(LIBFTDIR)
	@make bonus -C libft > /dev/null 2>&1

$(LIBFTDIR) :
	@echo "$(COLOR_GREEN)"
	git clone git@github.com:theyenerkaan/libft.git libft
	@echo "$(COLOR_RESET)" 

$(PRINTF) : $(PRINTFDIR)
	@make -C printf > /dev/null 2>&1

$(PRINTFDIR) :
	@echo "$(COLOR_YELLOW)"
	git clone git@github.com:theyenerkaan/printf.git printf
	@echo "$(COLOR_RESET)"

$(GNL) : $(GNLDIR)
	@echo "$(COLOR_GREEN)"
	@make -C get_next_line > /dev/null 2>&1
	@echo "$(COLOR_RESET)"

$(GNLDIR) :
	git clone git@github.com:theyenerkaan/get_next_line_true.git get_next_line

update :
	@cd libft && git pull
	@cd printf && git pull
	@cd get_next_line && git pull

bonus : all $(CHECKER) 

$(CHECKER) : $(LIBFT) $(PRINTF) $(B_OBJ) $(B_HEADER) $(GNL) 
	@$(CC) $(B_OBJ) $(LIBFT) $(PRINTF) $(GNL) -o $(CHECKER)
	@echo "$(COLOR_PURPLE)checker compiling...$(COLOR_RESET)"

clean :
	@rm -rf $(OBJ) $(B_OBJ)
	@make clean -C libft  > /dev/null 2>&1
	@make clean -C printf > /dev/null 2>&1
	@make clean -C get_next_line > /dev/null 2>&1

fclean :
	@rm -rf $(OBJ) $(NAME) $(B_OBJ) $(CHECKER)
	@make fclean -C libft > /dev/null 2>&1
	@make fclean -C printf > /dev/null 2>&1
	@make fclean -C get_next_line > /dev/null 2>&1

re : fclean all
