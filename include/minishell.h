/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:14:06 by azahajur          #+#    #+#             */
/*   Updated: 2024/11/04 16:35:17 by azahajur         ###   ########.fr       */
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

// estructura general de datos de la shell
typedef struct s_cmd
{
	char			**argum;
	struct s_redir	*redir;
}					t_cmd;

typedef struct s_pipe
{
	int flag; // si hay uno, sino cero
}					t_pipe;

typedef struct s_redir
{
	int				f_red_input;
	int				f_red_output;
	int				f_red_delimit;
	int				f_red_heredoc;
	char			*fdin;  // nombre de archivo de entrada
	char			*fdout; // nombre de archivo de salida
}					t_redir;

typedef struct s_token
{
	struct s_cmd	*cmd;
	struct s_pipe	*pipe;
	struct s_token	*head;
	struct s_token	*next;
	// struct s_token  *prev;// lo necesito si es doblemente enlazada
}					t_token;

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
void				execute_cmd(char *path, t_token *token, char **env);

#endif