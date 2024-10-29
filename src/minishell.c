/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:14:01 by azahajur          #+#    #+#             */
/*   Updated: 2024/10/29 17:30:48 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    init_list(t_token *token)
{
    t_token *node;

    node = malloc(sizeof(t_token));
    node->cmd = malloc(sizeof(t_cmd));
    token->next = NULL;
}


int main(int argc, char **argv, char **env)
{
    char  *read_line;
    t_token *token;
    
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
        init_token(token);
        //tokenizar, parseo. Limpiar de parentesis abiertos o cerrados, 
        //símbolos especiales. En el parseo se comprueban los errores
        //de gramática.
        //Tokenizar tiene que hacer split tieniendo en cuenta los simbolos
        //especiales, y segun que simbolos enviar el contenido a la struct
        //correspondiente.
        token->cmd->argum = tokenizer(read_line, '|', '>', '<');
        //revisar casos especiales. Redirecciones o built-in.
        //ejecutar con pipes y ejecutar sin pipes.
        if (pipes() == 0)
        {
            execute_multi_cmd();
        }
        else
        {
        //Solo llegamos aquí si hay un comando que no es builtin y 
        //no hay pipes. Puede haber redirecciones. Aquí saldrán los
        //otros errores, como haber escrito mal los comandos.
            execute_cmd();
        }
        
    }
    
    
       
}