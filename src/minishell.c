/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:14:01 by azahajur          #+#    #+#             */
/*   Updated: 2024/11/22 16:06:31 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_nword(char *s, char p, char o, char i, char d, char a)
{
	int	cnt;
	int	wd;

	wd = 0;
	cnt = 0;
	while (*s)
	{
		if (*s != ' ' && *s != p && *s != o && *s != i && *s != d && *s != a
			&& cnt == 0)
		{
			wd++;
			cnt = 1;
		}
		else if (*s == ' ' || *s == p || *s == o || *s == i || *s == d
			|| *s == a)
			cnt = 0;
		s++;
	}
	return (wd);
}

char	**tokenizer(char *read_line)
{
	int		nw;
	int		i;
	char	**str;

	nw = ft_nword(read_line, '|', '>', '<', '<<', '>>');
	// str = (char **)malloc((nw + 1) * sizeof(char *));
	// if (!str)
	// 	return (NULL);
	// nw = 0;
	// i = 0;
	// while (*read_line)
	// {
	// }
}

int	main(int argc, char **argv, char **env)
{
	char *read_line;
	t_mshell *token;

	(void)argv;
	(void)argc;
	g_sig = 0;
	while (1)
	{
		read_line = readline("🌝 Minishell$>");
		if (!read_line)
		{
			printf("[Error]: readline_Fail");
			exit(1);
		}
		add_history(read_line);
		init_struct(token);
		// tokenizar, parseo. Limpiar de parentesis abiertos o cerrados,
		// símbolos especiales. En el parseo se comprueban los errores
		// de gramática.
		// Tokenizar tiene que hacer split tieniendo en cuenta los simbolos
		// especiales, y segun que simbolos enviar el contenido a la struct
		// correspondiente.
		token->cmd_list->argum = tokenizer(read_line);
		// revisar casos especiales. Redirecciones o built-in.
		// ejecutar con pipes y ejecutar sin pipes.
		if (pipes() == 0)
		{
			execute_multi_cmd();
		}
		else
		{
			// Solo llegamos aquí si hay un comando que no es builtin y
			// no hay pipes. Puede haber redirecciones. Aquí saldrán los
			// otros errores, como haber escrito mal los comandos.
			execute_cmd();
		}
	}
}