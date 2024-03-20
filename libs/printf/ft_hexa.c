/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:26:52 by baiannon          #+#    #+#             */
/*   Updated: 2023/12/13 16:39:59 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_base(unsigned long int n, char c)
{
	int	len;

	len = 0;
	if (n > 15)
		len += ft_hexa_base(n / 16, c);
	if (c == 'x')
		len += write(1, &"0123456789abcdef"[n % 16], 1);
	else if (c == 'X')
		len += write(1, &"0123456789ABCDEF"[n % 16], 1);
	return (len);
}

int	ft_hexa_p(unsigned long int ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x") + ft_hexa_base(ptr, 'x');
	return (len);
}
