/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:47:57 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/09 14:52:37 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	index;
	size_t	index2;

	index = 0;
	if (str == NULL && len == 0)
		return (NULL);
	if (ft_strlen(to_find) == 0)
		return ((char *) str);
	while (str[index])
	{
		index2 = 0;
		if (str[index] == to_find[index2])
		{
			while (to_find[index2] != '\0'
				&& str[index + index2] == to_find[index2]
				&& index + index2 < len)
			{
				index2++;
				if (to_find[index2] == '\0' )
					return ((char *)str + index);
			}
		}
		index++;
	}
	return (0);
}
