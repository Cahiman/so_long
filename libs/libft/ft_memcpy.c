/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:37:16 by baiannon          #+#    #+#             */
/*   Updated: 2024/03/21 17:10:18 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srce;
	size_t			i;

	dst = (unsigned char *) dest;
	srce = (unsigned char *) src;
	i = 0;
	if (n > 0 && !dest && !src)
		return (dest);
	while (i < n)
	{
		dst[i] = srce[i];
		i++;
	}
	return (dst);
}
