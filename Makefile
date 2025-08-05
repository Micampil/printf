# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Micampil <micampil@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 13:00:52 by Micampil          #+#    #+#              #
#    Updated: 2025/05/15 15:59:01 by Micampil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_printf.c ft_printf_utils.c ft_printf_hex.c
BONUS = 

OBJS = $(FILES:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCLUDES = -I. -I$(LIBFT_PATH)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Compilled PrintF..."
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C $(LIBFT_PATH)

bonus: $(LIBFT) $(OBJS) $(BONUS_OBJS)
	@echo "Compilled PrintF with bonus..."
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@touch bonus

clean:
	@echo "Cleaned up..."
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@echo "Removed libftprintf.a..."
	@$(RM) $(NAME)
	@$(RM) bonus
	@make -C $(LIBFT_PATH) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
