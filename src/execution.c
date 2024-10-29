/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:37:23 by azahajur          #+#    #+#             */
/*   Updated: 2024/10/29 16:40:33 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minishell.h"

void    execute_cmd(char *path, t_token *token, char **env)
{
	char	*cmd;
	
	
	cmd = ft_path(path, env);
	if (execve(cmd, token, env) < 0)
		error_exec(1); //[Error]: Failed_execve.
}


