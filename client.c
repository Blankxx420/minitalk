/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:37:48 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/28 08:38:09 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_reciever;

g_reciever = 0;

void	sig_handler(int signum)
{
	int bit_send;
	
	bit_send = 0;
	g_reciever = 1;
	if (signum == SIGUSR2)
		bit_send++;
	
}

int char_to_binary(int pid, char c)
{
	int bit_index;
	int bit;
	
	bit_index = 7;
	while (bit_index > 0)
	{
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_index--;
		while (g_reciever == 0)
		{
			if (bit == 50)
			{
				ft_printf("Error : No response from server");
				exit(1);
			}
			bit++;
			usleep(100);
		}
	}
}

int main(int argc , char **argv)
{
	struct sigaction sa;
	int		pid;

	if (argc != 3)
		return (1);
	ft_bzero(&sa, 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = sig_handler;
	pid = ft_atoi(argv[1]);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (SIGUSR1 == -1 || SIGUSR2 == -1)
		return (1);
	return (0);
}