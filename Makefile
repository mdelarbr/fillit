# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/02 17:42:56 by mdelarbr     #+#   ##    ##    #+#        #
#    Updated: 2018/11/12 20:30:02 by husahuc     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc
CFLAGS += -Wall -Wextra -Werror
RM = rm -f
NAME = fillit
SRCS = btk.c main.c put_tetrominos_2.c point.c put_tetrominos_bis.c
OBJETS = $(SRCS:.c=.o)
INC = libft

all: $(NAME)

$(NAME): $(OBJETS) $(INC)
	@echo "compilation" $(INC)
	@make -C $(INC)
	@echo "compilation" $(NAME)
	@$(CC) -g3 -o $(NAME) $(OBJETS) $(INC)/libft.a -L $(INC)

.PHONY: clean fclean re

clean:
	@echo "clean"
	@make clean -C $(INC)
	$(RM) $(OBJETS)

fclean: clean
	@echo "fclean"
	@make fclean -C $(INC)
	@$(RM) $(NAME)

re: fclean all

