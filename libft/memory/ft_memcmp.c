/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:26:39 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/09 14:18:19 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t			index;
	unsigned char	*p1;
	unsigned char	*p2;

	index = 0;
	p1 = (unsigned char *)pointer1;
	p2 = (unsigned char *)pointer2;
	while (index < size)
	{
		if (p1[index] != p2[index])
		{
			return ((int) p1[index] - (int) p2[index]);
		}
		index++;
	}
	return (0);
}
