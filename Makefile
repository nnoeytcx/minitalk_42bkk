# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 21:46:33 by tpoungla          #+#    #+#              #
#    Updated: 2023/07/16 23:23:37 by tpoungla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SVR_NAME = server
CNT_NAME = client

# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

SVR_SRCS = server.c
CNT_SRCS = client.c
UTILS = put.c tool.c

OBJ	:= $(FILES:.c=.o)

all: $(NAME)

$(NAME): server client

server:
	gcc -Wall -Wextra -Werror $(UTILS) $(SVR_SRCS) -o $(SVR_NAME)

client:
	gcc -Wall -Wextra -Werror $(UTILS) $(CNT_SRCS) -o $(CNT_NAME)

norm:
	norminette -R checkforbiddensourceheader $(FILES)
	norminette -R checkdefine minitalk.h
clean:
	@rm -f $(SVR_NAME)
	@rm -f $(CNT_NAME)
	@echo "yep, cleaned"

fclean: clean
	@echo "tidy -- totally cleaned!"

re: fclean all

.PHONY: clean fclean all re norm