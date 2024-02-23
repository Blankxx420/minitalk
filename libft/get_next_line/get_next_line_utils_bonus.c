/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:42:54 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/22 10:47:22 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_check_newline(char *stock)
{
	int	i;

	i = 0;
	if (stock == NULL)
		return (0);
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (1);
		i++;
	}
	return (stock[i]);
}

char	*ft_strjoinf(char *s1, char *s2)
{
	char	*str;
	int		size_s1;
	int		size_s2;
	int		index;
	int		j;

	index = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = ft_calloc((size_s1 + size_s2 + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	while (index < size_s1)
	{
		str[index] = s1[index];
		index++;
	}
	while (j < size_s2)
		str[index++] = s2[j++];
	free(s1);
	return (str);
}
