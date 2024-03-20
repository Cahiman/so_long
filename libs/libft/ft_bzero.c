/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:23:58 by baiannon          #+#    #+#             */
/*   Updated: 2023/11/20 14:08:50 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ss;
	size_t	i;

	ss = s;
	i = 0;
	while (i < n)
	{	
		ss[i] = '\0';
		i++;
	}
}

// /*#include <stdio.h>
// int	main()
// {
// 	char s1[100]="Je test";
// 	size_t n = 3;
// 	ft_bzero(s1, n);
// 	printf("%s", s1);
// }