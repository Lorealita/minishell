/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:51:48 by azahajur          #+#    #+#             */
/*   Updated: 2024/05/17 17:34:34 by azahajur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	const char	*str;
	size_t		cnt;

	str = (const char *)s;
	cnt = 0;
	while (cnt < len)
	{
		if (str[cnt] == c)
		{
			return ((void *)(str));
		}
		str++;
		cnt++;
	}
	return (0);
}
