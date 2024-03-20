/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:49:56 by baiannon          #+#    #+#             */
/*   Updated: 2023/11/17 17:10:42 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	n;
	int	res;
	int	sign;

	n = 0;
	res = 0;
	sign = 1;
	while ((nptr[n] >= 9 && nptr[n] <= 13) || nptr[n] == 32)
		n++;
	if (nptr[n] == '+')
		n++;
	else if (nptr[n] == '-')
	{
		sign *= -1;
		n++;
	}
	while (nptr[n] >= '0' && nptr[n] <= '9')
	{
		res = res * 10 + nptr[n] - '0';
		n++;
	}
	return (res * sign);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main()
// {
// 	char str[]="   +123ab567";

// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// }