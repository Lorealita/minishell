/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:37:23 by azahajur          #+#    #+#             */
/*   Updated: 2024/10/25 14:24:22 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minishell.h"

void    execute_cmd(char *path, char **token, char **env)
{
    
    if (execve(path, token, env) < 0)
		return(1);
}