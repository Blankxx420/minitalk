/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:35:41 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/09 14:53:28 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int				size;
	unsigned char	*str;

	size = ft_strlen(string);
	str = (unsigned char *) string;
	if (str[size] == '\0' && (char) c == '\0')
		return ((char *)str + size);
	while (size >= 0)
	{
		if (str[size] == (char) c)
			return ((char *)str + size);
		size--;
	}
	str = NULL;
	return ((char *)str);
}
