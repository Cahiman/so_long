/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baiannon <baiannon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:34:17 by baiannon          #+#    #+#             */
/*   Updated: 2023/12/13 16:40:54 by baiannon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

unsigned int	ft_putnbr_unsigned(unsigned int nb);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putnbr(int nb, int *len);
int				ft_printf(const char *str, ...);
int				ft_hexa_base(unsigned long int n, char c);
int				ft_hexa_p(unsigned long int ptr);
int				check_char(char c, va_list args);

#endif