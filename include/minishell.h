/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:14:06 by azahajur          #+#    #+#             */
/*   Updated: 2024/11/11 19:50:08 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <sys/param.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <termios.h>
# include <unistd.h>

// variable global para señales
int					g_sig;

typedef enum e_lexer
{
			CMD,
			PIPE,
			REDIR,
}			t_lexer;

typedef enum e_red_type
{
			INPUT,
			OUTPUT,
			DELIMIT,
			APPEND,
}			t_red_type;

typedef struct	s_lex_list
{
	t_lexer				lex_type;
	struct s_lex_list	*next;	
}				t_lex_list;

typedef struct s_cmd
{
	char			**argum;
	struct s_redir	*redir;
	struct s_cmd	*next;
}					t_cmd;

//Si hacemos la comprobación gramatical lo primero de todo, comprobamos
//si las pipes están bien puestas. Si lo están, se llega a ejecución.
//En ese caso, podemos prescindir de esta estructura y simplemente si
//hay varios comandos y llegamos a ejecución es porque hay pipes.
typedef struct s_pipe
{
	int flag; // si hay uno, sino cero
}					t_pipe;

typedef struct s_redir
{
	// int				f_red_input;//se puede hacer con enum tb, que contenga >, <, >>, <<.
	// int				f_red_output;
	// int				f_red_delimit;
	// int				f_red_heredoc;
	t_red_type		red_type;
	char			*fdin;  // nombre de archivo de entrada
	char			*fdout; // nombre de archivo de salida
	struct s_redir	*next;
}					t_redir;

typedef struct s_mshell
{
	t_lex_list		*lexer_list;
	struct s_cmd	*cmd_list;
	struct s_pipe	*pipe; //puede que no haga falta
	// struct s_token  *prev;// lo necesito si es doblemente enlazada
}					t_mshell;

// EXECUTION
/**
 * @brief Ejecuta los comandos sin pipes. Se gestionan los fd, las redirecciones
 * necesarias de entradas y salidas si hay files, se ejecuta el comando y vuelve
 * al bucle.
 *
 * @param path
 * Es la ruta al comando que debe ejecutarse.
 * @param token
 * Es el array donde estan almacenados los parámetros de entrada ya
 * separados y listos para procesarse.
 * @param env
 * Parámetro de main que almacena las variables de entorno. Es un parámetro
 * especial como argc y argv.
 */
void				execute_cmd(char *path, t_mshell *token, char **env);

#endif