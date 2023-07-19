/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:46:36 by tpoungla          #+#    #+#             */
/*   Updated: 2023/07/17 02:03:16 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bi(pid_t pid, char *str)
{
	int	bs;
	int	i;

	i = 0;
	while (str[i])
	{
		bs = 0;
		while (bs < 8)
		{
			if (str[i] & 0x80 >> bs)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit (1);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit (1);
			}
			usleep(100);
			bs++;
		}
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	if (pid > 0)
		send_bi(pid, str);
	return (0);
}
