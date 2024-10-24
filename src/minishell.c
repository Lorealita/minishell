/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:14:01 by azahajur          #+#    #+#             */
/*   Updated: 2024/10/24 17:45:20 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int main(int argc, char **argv, char **env)
{
    char  *read_line;
    
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
        //tokenizar, revisar los casos especiales (parentesis, redirecciones..)
        //parseo 
        //ejecutar con pipes y ejecutar sin pipes
        
        
    }
    
    
       
}