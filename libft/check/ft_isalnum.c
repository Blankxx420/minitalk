/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:29:29 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/22 10:46:03 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int character)
{
	if ((character <= 57 && character >= 48)
		|| (character >= 65 && character <= 90)
		|| (character >= 97 && character <= 122))
		return (1);
	return (0);
}
