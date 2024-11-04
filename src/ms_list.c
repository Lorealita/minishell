/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:54 by azahajur          #+#    #+#             */
/*   Updated: 2024/11/04 16:03:19 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_list(t_token *token)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	node->cmd = malloc(sizeof(t_cmd));
	token->next = NULL;
}

void    init_argum(void)
{
    t_cmd   *node;
    //numero de palabras que contiene. Cuando haya parseo se calculara ahí
    int     nw = 5;
    int     cnt = 0;

    node->argum = malloc(nw)(sizeof(char **));
    while(cnt < (nw - 1))
    {
        argum[cnt] = malloc (sizeof(char *));
        cnt++;
    }
}