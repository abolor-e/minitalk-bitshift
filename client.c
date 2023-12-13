/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:47:03 by abolor-e          #+#    #+#             */
/*   Updated: 2023/12/13 11:58:07 by abolor-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pid_check(char *pid_str)
{
	int	i;
	int	pid;

	if (!pid_str)
		return (0);
	i = 0;
	while (pid_str[i] != '\0')
	{
		if (pid_str[i] > 57 || pid_str[i] < 48)
			return (0);
		i++;
	}
	pid = ft_atoi(pid_str);
	if (pid < 2 || kill(pid, 0) == -1)
		return (0);
	return (1);
}

void	binary_convertor(int pid, int ascii)
{
	int	index;

	index = 8;
	while (index-- > 0)
	{
		if (ascii % 2 == 1)
		{
			kill(pid, SIGUSR2);
			usleep(400);
		}
		else
		{
			kill(pid, SIGUSR1);
			usleep(400);
		}
		ascii /= 2;
	}
}

void	char_to_binary(char *str, int pid)
{
	int	i;
	int	a;
	int	ascii;

	a = 0;
	if (!str)
		return ;
	i = ft_strlen(str);
	while (a < i)
	{
		ascii = (unsigned char)str[a];
		binary_convertor(pid, ascii);
		a++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (pid_check(av[1]) == 0)
		{
			write(1, "Error: Invalid Process ID\n", 26);
			return (1);
		}
		char_to_binary(av[2], ft_atoi(av[1]));
	}
	else if (ac != 3)
	{
		write(1, "Error: Check argument numbers\n", 30);
		return (1);
	}
	return (0);
}
