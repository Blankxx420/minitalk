/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:37:48 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/29 15:31:05 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_reciever = 0;

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit_send = 0;

	(void) info;
	(void) context;
	g_reciever = 1;
	if (signum == SIGUSR2)
		bit_send++;
	if (signum == SIGUSR1)
		ft_printf("number bite recieved %d\n", bit_send);
}

void	char_to_binary(int pid, char c)
{
	int	bit_index;
	int	bit;

	bit_index = 7;
	while (bit_index >= 0)
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
		g_reciever = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;
	int					i;

	if (argc != 3)
		return (1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sig_handler;
	pid = ft_atoi(argv[1]);
	if (pid == -1 || pid == 0)
		return (1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (SIGUSR1 == -1 || SIGUSR2 == -1)
		return (1);
	while (argv[2][i])
	{
		char_to_binary(pid, argv[2][i]);
		i++;
	}
	char_to_binary(pid, argv[2][i]);
	char_to_binary(pid, '\n');
	return (0);
}
