/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:13:33 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/16 15:39:20 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count_word(const char *str, char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	if (str == NULL)
		return (0);
	while (str[index])
	{
		if (str[index] != c && (index == 0 || str[index - 1] == c))
			count++;
		index++;
	}
	return (count);
}

static int	ft_get_size_word(const char *str, char c)
{
	int	index;

	index = 0;
	while (str[index] != c && str[index] != '\0')
	{
		index++;
	}
	return (index);
}

void	ft_free_tab(char **tab)
{
	int	index;

	index = 0;
	while (tab[index])
	{
		free(tab[index]);
		tab[index] = NULL;
		index++;
	}
	free(tab);
	tab = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_word;
	int		index;
	int		len_word;

	index = -1;
	len_word = 0;
	nb_word = ft_count_word(s, c);
	tab = ft_calloc(sizeof(char *), nb_word + 1);
	if (tab == NULL)
		return (NULL);
	while (++index < nb_word)
	{
		while (*s == c || len_word > 0)
		{
			s++;
			len_word--;
		}
		len_word = ft_get_size_word(s, c);
		tab[index] = ft_calloc(sizeof(char), len_word + 1);
		if (tab[index] == NULL)
			ft_free_tab(tab);
		tab[index] = ft_memcpy(tab[index], s, len_word);
	}	
	return (tab);
}
