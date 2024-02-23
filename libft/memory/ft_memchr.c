/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:49:17 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/09 14:17:15 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr( const void *memoryblock, int searchedchar, size_t size)
{
	size_t			index;
	unsigned char	*memo;

	index = 0;
	memo = (unsigned char *) memoryblock;
	while (index < size)
	{
		if (memo[index] == (unsigned char) searchedchar)
			return (memo + index);
		index++;
	}
	memo = NULL;
	return (memo);
}
