/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:49:55 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/09 14:54:14 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_test_str(char c, char const *set)
{
	int	index;

	index = 0;
	while (set[index])
	{
		if (c == set[index])
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	while (ft_test_str(s1[0], set))
		s1++;
	size = ft_strlen(s1);
	while (size > 0 && ft_test_str(s1[size - 1], set))
		size--;
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, size);
	return (str);
}
