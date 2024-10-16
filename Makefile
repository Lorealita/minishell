# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 16:13:57 by azahajur          #+#    #+#              #
#    Updated: 2024/10/16 17:07:05 by azahajur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -g -fsanitize=address / -g -fsanitize=thread
NAME = minishell
FILES = src/minishell.c \

# Genera los archivos .o para cada archivo .c
OBJ = $(FILES:.c=.o)
FLAGS = -Wall -Werror -Wextra
USER = azahajur
FLAGSREAD = lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)
	
#Solo se compilan los archivos que han cambiado. (Es una regla de cancelación, evita que se recompilen archivos que no se han actualizado).
src/%.o: src/%.c
	gcc $(FLAGS) $(FLAGSREAD) -c -o $@ $<

# Borra todos los archivos de la variable OBJ
clean:
	rm -f $(OBJ) 
	
# Borra todos los archivos de la variable OBJ y NAME
fclean: clean
	rm -f $(NAME) $(OBJ)
	
# Hace un re-make, borra todo y ejecuta el Make como si fuera la primera vez.
re: fclean all 

# le dice al make que estos nombres no son archivos
.PHONY: re all fclean clean