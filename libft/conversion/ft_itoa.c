/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:47:42 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/09 15:23:26 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_nbrlen(long int n)
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

char	*ft_itoa(int n)
{
	int			nbr_len;
	char		*str;
	long int	nbr;

	nbr = n;
	nbr_len = ft_nbrlen(nbr);
	if (n == 0)
		return (ft_strdup("0"));
	if (nbr < 0)
		nbr *= -1;
	str = ft_calloc(sizeof(char), nbr_len + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	while (nbr)
	{
		str[nbr_len - 1] = (nbr % 10) + 48;
		nbr /= 10;
		nbr_len--;
	}
	return (str);
}
