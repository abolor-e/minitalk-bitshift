/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowhexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:12:41 by abolor-e          #+#    #+#             */
/*   Updated: 2023/11/16 12:55:58 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowhexa(unsigned int lh, int *count)
{
	if (lh < 0)
	{
		if (ft_nputchar('-', count) == -1)
			return (-1);
		if (ft_lowhexa(-lh, count) == -1)
			return (-1);
	}
	if (lh > 15)
	{
		if (ft_lowhexa(lh / 16, count) == -1)
			return (-1);
		if (ft_lowhexa(lh % 16, count) == -1)
			return (-1);
	}
	if (lh >= 0 && lh <= 15)
	{
		if (ft_nputchar("0123456789abcdef"[lh], count) == -1)
			return (-1);
	}
	return (0);
}
