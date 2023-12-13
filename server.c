/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:48:26 by abolor-e          #+#    #+#             */
/*   Updated: 2023/12/13 11:45:07 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	binary_to_char_handler(int sig)
{
	static unsigned char	binary_string = 0;
	static int				i = 0;

	if (sig == SIGUSR1)
	{
		binary_string += 0 << i;
	}
	else if (sig == SIGUSR2)
	{
		binary_string += 1 << i;
	}
	i++;
	if (i == 8)
	{
		i = 0;
		write(1, &binary_string, 1);
		binary_string = 0;
	}
}

int	main(void)
{
	int	pid;
	int	i;

	i = 1;
	pid = getpid();
	ft_printf("Process ID: %d\n", pid);
	while (i != 0)
	{
		signal(SIGUSR1, &binary_to_char_handler);
		signal(SIGUSR2, &binary_to_char_handler);
		pause ();
	}
	return (0);
}
