# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galee <galee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 20:32:13 by galee             #+#    #+#              #
#    Updated: 2021/12/03 20:32:13 by galee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = main.c \
		utils.c \
		free.c \
		init.c \
		work.c \
		time.c
OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBS = -lpthread

NAME= philo

all: $(NAME)

$(NAME): $(OBJS)
	gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re