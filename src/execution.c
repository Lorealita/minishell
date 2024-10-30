/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:37:23 by azahajur          #+#    #+#             */
/*   Updated: 2024/10/30 17:09:42 by azahajur         ###   ########.fr       */
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


void	execute_multi_cmd(char *path, t_token *token, char **env)
{
	int		cnt;
	int		fd1;
	int		fd2;
	char	**arg;
	char	*path;

	//si existe f_red_output, entonces abro el archivo de salida y le asigno un fd.
	if (token->redir->f_red_output)
	{
		fd2 = open(token->redir->fdout, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	}
	if (token->redir->fd_red_input)
	{
		fd1 = open(token->redir->fdin, O_RDONLY);
	}
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	envario(fd1, env, argv[2]);
	while (argv[cnt] && cnt < argc - 2)
	{
		envario(STDOUT_FILENO, env, argv[cnt]);
		cnt++;
	}                      
	arg = ft_split(argv[cnt], ' ');
	path = ft_path(arg[0], env);
	if (execve(path, arg, env) < 0)
		exit(1);
}