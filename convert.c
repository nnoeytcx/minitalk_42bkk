/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:04:16 by tpoungla          #+#    #+#             */
/*   Updated: 2023/07/16 22:32:26 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	ft_str_to_bi(pid_t pid, char *str)
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
				if (kill(pid, SIGUSR1) == -1)
					exit (1);
			else
				if (kill(pid, SIGUSR2) == -1)
					exit (1);
			bs++;
		}
		printf("[%d]: %c\n", str[i], str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	ft_str_to_bi(argv[1], argv[2]);
	return (0);
}
