/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:25:00 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/09 14:48:54 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp( const char *first, const char *second, size_t length)
{
	size_t			index;
	unsigned char	*s1;
	unsigned char	*s2;

	index = 0;
	s1 = (unsigned char *) first;
	s2 = (unsigned char *) second;
	while ((s1[index] || s2[index]) && index < length)
	{
		if (s1[index] != s2[index])
			return ((int) s1[index] - (int) s2[index]);
		index++;
	}
	return (0);
}
