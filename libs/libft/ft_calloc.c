/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:35:18 by baiannon          #+#    #+#             */
/*   Updated: 2023/11/17 12:03:49 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*t;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb * size < nmemb || nmemb * size < size)
		return (NULL);
	t = malloc(nmemb * size);
	if (t == 0)
		return (NULL);
	while (nmemb * size > i)
	{
		t[i] = '\0';
		i++;
	}
	return (t);
}
