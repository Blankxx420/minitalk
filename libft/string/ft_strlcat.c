/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:46:36 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/09 14:45:35 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	index;
	size_t	size_dest;
	size_t	size_src;
	size_t	initial_dest_len;

	index = 0;
	if ((dest == NULL || src == NULL) && n == 0)
		return (0);
	initial_dest_len = ft_strlen(dest);
	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (size_dest >= n)
		return (size_src + n);
	while (src[index] && size_dest + 1 < n)
	{
		dest[size_dest] = src[index];
		index++;
		size_dest++;
	}
	dest[size_dest] = '\0';
	return (size_src + initial_dest_len);
}
