/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:58:31 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/09 14:25:34 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*csrc;
	unsigned char	*cdest;

	csrc = (unsigned char *) src;
	cdest = (unsigned char *) dest;
	if (src == NULL && dest == NULL && size != 0)
		return (dest);
	if (dest < src)
		ft_memcpy(cdest, csrc, size);
	else
	{
		while (size > 0)
		{
			cdest[size - 1] = csrc[size - 1];
			size--;
		}
	}
	return (cdest);
}
