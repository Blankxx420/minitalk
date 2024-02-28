/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:37:52 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/27 13:41:02 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(void)
{
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_printf("Error : no arguments requiere\n");
		return(1);
	}
	else
	{	(void) argv;
		print_pid();
		while (42)
			pause();
	}
	return (0);
}