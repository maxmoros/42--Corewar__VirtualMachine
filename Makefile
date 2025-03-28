# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qpeng <qpeng@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/16 23:19:51 by qpeng             #+#    #+#              #
#    Updated: 2019/07/17 20:14:16 by qpeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = champion.c\
		handler.c\
		helper.c\
		lib.c\
		loader.c\
		main.c\
		memory.c\
		init.c\
		op.c\
		process.c

FILES = $(addprefix src/, $(SRC))

all:
	gcc -g -Iinclude -fsanitize=address $(FILES)

test:
	gcc -g -Iinclude -Wall -Werror -Wextra -fsanitize=address FILES tests/libunity.a