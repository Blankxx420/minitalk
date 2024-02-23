/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:40:20 by brguicho          #+#    #+#             */
/*   Updated: 2023/12/30 00:47:00 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstrlen(char *str)
{
	int	index;

	index = 0;
	if (str == NULL)
		return (ft_putstrlen("(null)"));
	while (str && str[index])
	{
		ft_putcharl(str[index]);
		index++;
	}
	return (index);
}
