/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:40:16 by baiannon          #+#    #+#             */
/*   Updated: 2023/11/16 14:27:55 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ss;
	size_t	i;

	ss = s;
	i = 0;
	while (i < n)
	{
		ss[i] = c;
		i++;
	}
	return (s);
}

// /*
// #include <stdio.h>
// int	main()
// {
// 	char s[50]="";
// 	int c = 'B';
//         size_t n = 5;
// 	printf("%s", (char *)ft_memset(s, c, n));
// }
