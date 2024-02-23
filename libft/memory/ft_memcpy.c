/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:53:52 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/09 14:24:00 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t			index;
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *) destination;
	src = (unsigned char *) source;
	index = 0;
	if (source == NULL && destination == NULL && size != 0)
		return (destination);
	while (index < size)
	{
		dest[index] = src[index];
		index++;
	}
	return (destination);
}
