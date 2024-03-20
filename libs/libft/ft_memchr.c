/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:40:43 by baiannon          #+#    #+#             */
/*   Updated: 2023/11/16 16:23:27 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s1;

	s1 = (char *) s;
	i = 0;
	while (i < n)
	{
		if (s1[i] == (char)c)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}

// #include <string.h>

// /*int	main()
// {
// 	char s[]="TEST";
// 	int c = 'H';
//     size_t n = 4;

// 	printf("%s\n", (char *)ft_memchr(s, c, n));
// 	printf("%s\n", (char *)memchr(s, c, n));
// }