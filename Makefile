# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 19:16:41 by ggregoir          #+#    #+#              #
#    Updated: 2018/03/22 16:28:28 by ggregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rand

SRC		= rand.c\
		  utils.c\

OBJ		= $(patsubst %.c,%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror -Ofast  $(SRC) -o $(NAME)
	@echo '\033[32m[ ✔ ] \n\033[0m' "Create exec"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	@echo '\033[0m[ ✔ ] \n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	@echo '\033[31m[ ✔ ] \n\033[0m' "Clean Lib"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	@echo '\033[31m[ ✔ ] \n\033[0m' "Fclean Lib"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all