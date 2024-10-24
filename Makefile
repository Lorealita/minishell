# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 16:13:57 by azahajur          #+#    #+#              #
#    Updated: 2024/10/24 13:14:49 by azahajur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -g -fsanitize=address / -g -fsanitize=thread
NAME = minishell
FILES = src_exec/minishell.c \
LIBFT = ./include/Libft_final/libft.a
PRINTF = ./include/Printf_final/printf.a
GETNEXTLINE = ./include/GetNextLine_final/get_next_line.a

# Genera los archivos .o para cada archivo .c
OBJ = $(FILES:.c=.o)
FLAGS = -Wall -Werror -Wextra
USER = azahajur
FLAGSREAD = lreadline -L /home/$(USER)/.brew/opt/readline/lib -I /home/$(USER)/.brew/opt/readline/include

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(GETNEXTLINE)
	gcc $(OBJ) -o $(NAME)
	
#Solo se compilan los archivos que han cambiado. (Es una regla de cancelación, evita que se recompilen archivos que no se han actualizado).
src/%.o: src/%.c
	gcc $(FLAGS) $(FLAGSREAD) -c -o $@ $<

# Compila el make de Libft
$(LIBFT):
	make -C include/Libft_final
	
# Compila el make de Printf
$(PRINTF):
	make -C include/Printf_final

# Compila el make de GetNextLine
$(GETNEXTLINE):
	make -C include/GetNextLine_final

# Borra todos los archivos de la variable OBJ
clean:
	rm -f $(OBJ)
	make -C include/Libft_final clean
	make -C include/Printf_final clean
	make -C include/GetNextLine_final clean
	
# Borra todos los archivos de la variable OBJ y NAME
fclean: clean
	rm -f $(NAME) $(OBJ)
	make -C include/Libft_final fclean
	make -C include/Printf_final fclean
	make -C include/GetNextLine_final fclean
	
# Hace un re-make, borra todo y ejecuta el Make como si fuera la primera vez.
re: fclean all 

# le dice al make que estos nombres no son archivos
.PHONY: re all fclean clean