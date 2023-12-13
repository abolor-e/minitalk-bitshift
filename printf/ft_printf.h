/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:25:19 by abolor-e          #+#    #+#             */
/*   Updated: 2023/11/16 13:33:42 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_vprint(const char *fmt, va_list args, int *count);
int	check(unsigned long args, char c, int *count);
int	ft_nputchar(char c, int *count);
int	ft_nputnbr(long n, int *count);
int	ft_pputnbr(unsigned int n, int *count);
int	ft_nputstr(char *str, int *count);
int	ft_lowhexa(unsigned int lh, int *count);
int	ft_upphexa(unsigned int uh, int *count);
int	ft_add(unsigned long addr, int *count);
int	ft_putaddr(void *addr, int *count);

#endif
