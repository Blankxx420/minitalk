/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:46:16 by brguicho          #+#    #+#             */
/*   Updated: 2023/12/30 00:46:57 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_nbrlen(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbrl(int n)
{
	int	nbr_len;

	nbr_len = ft_nbrlen(n);
	if (n == 0)
		return (ft_putstrlen("0"));
	if (n == -2147483648)
		return (ft_putstrlen("-2147483648"));
	if (n < 0)
	{
		ft_putcharl('-');
		n = n * -1 ;
	}
	if (n >= 10)
	{
		ft_putnbrl(n / 10);
		ft_putnbrl(n % 10);
	}
	else
		n = ft_putcharl(n + 48);
	return (nbr_len);
}
