/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:26:14 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/22 10:48:11 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr( const char *string, int searchedchar )
{
	int				index;
	unsigned char	*str;

	index = 0;
	str = (unsigned char *)string;
	while (string[index])
	{
		if (str[index] == (unsigned char)searchedchar)
			return ((char *)str + index);
		index++;
	}
	if (str[index] == '\0' && (unsigned) searchedchar == '\0')
		return ((char *)str + index);
	str = 0;
	return ((char *)str);
}
