/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:14:06 by azahajur          #+#    #+#             */
/*   Updated: 2024/10/25 14:22:39 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <limits.h>
# include <termios.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/param.h>
# include <readline/history.h>
# include <readline/readline.h>

//variable global para señales
int g_sig;

//estructura general de datos de la shell
typedef struct s_mshell
{
    char    *str;
    int     ty

}	t_mshell;


//EXECUTION
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
void    execute_cmd(char *path, char **token, char **env);

#endif