/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:24:08 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/09 14:45:17 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size_s1;
	int		size_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str = ft_calloc(size_s1 + size_s2 + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, size_s1 + 1);
	ft_strlcat(str + size_s1, s2, size_s2 + 1);
	return (str);
}
