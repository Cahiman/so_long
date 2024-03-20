/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:20:04 by baiannon          #+#    #+#             */
/*   Updated: 2023/11/16 14:15:15 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_drct(unsigned char *dst, unsigned char *srce, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		dst[i] = srce[i];
		i++;
	}
	return (dst);
}

void	*ft_memcpy_invrs(unsigned char *dst, unsigned char *srce, size_t n)
{
	size_t	i;

	i = n - 1;
	while (i > 0)
	{
		dst[i] = srce[i];
		i--;
	}
	dst[i] = srce[i];
	return (dst);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*srce;

	dst = (unsigned char *) dest;
	srce = (unsigned char *) src;
	if (dst == srce || n == 0)
		return (dest);
	if (dst > srce)
	{
		ft_memcpy_invrs(dst, srce, n);
	}
	if (src > dest)
	{
		ft_memcpy_drct(dst, srce, n);
	}
	return (dest);
}
