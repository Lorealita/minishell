/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:14:06 by azahajur          #+#    #+#             */
/*   Updated: 2024/10/25 09:29:26 by azahajur         ###   ########.fr       */
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


//MINISHELL


#endif