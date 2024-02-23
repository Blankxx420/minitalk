/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:53:47 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/16 14:46:27 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_atol(const char *str)
{
	int	i;
	long long int	sign;
	long long int	somme;

	somme = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] - '0' >= 0 && str[i] - '0' <= 9))
	{
		somme = somme * 10 + str[i] - '0';
		i++;
	}
	return (somme * sign);
}
