/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:35:34 by brguicho          #+#    #+#             */
/*   Updated: 2023/11/09 14:44:41 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;
	unsigned int	size;

	if (s == NULL)
		return ;
	size = ft_strlen(s);
	index = 0;
	while (index < size)
	{
		f(index, &s[index]);
		index++;
	}
}
