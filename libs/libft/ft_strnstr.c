/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:12:06 by baiannon          #+#    #+#             */
/*   Updated: 2023/12/01 18:17:55 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	char	*str;

	if (!big && len == 0)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)big;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <bsd/string.h>
// int	main()
// {
	// char s1[]="";
	// char s2[]="salut a tous`";
	// size_t len = 8;
	// printf("%p", ft_strnstr(s1, s2, len));
	// return(0);
// }