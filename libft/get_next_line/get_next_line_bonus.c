/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:31 by brguicho          #+#    #+#             */
/*   Updated: 2024/01/22 10:46:25 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char		*line;

	if (!stock[fd])
		stock[fd] = ft_calloc(1, 1);
	if (!stock[fd])
		return (NULL);
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_and_extract(fd, &stock[fd]);
	line = ft_get_line(stock[fd], line);
	stock[fd] = ft_clean_stock(stock[fd]);
	if (line && !*line && ft_strlen(stock[fd]) == 0)
	{
		free(line);
		free(stock[fd]);
		stock[fd] = NULL;
		line = NULL;
		return (NULL);
	}
	return (line);
}

void	ft_read_and_extract(int fd, char **stock)
{
	char	*buffer;
	int		reed;

	buffer = NULL;
	while (!ft_check_newline(*stock))
	{
		free(buffer);
		buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		reed = read(fd, buffer, BUFFER_SIZE);
		if (reed <= 0)
		{
			free(buffer);
			return ;
		}
		*stock = ft_strjoinf(*stock, buffer);
	}
	free(buffer);
}

char	*ft_get_line(char *stock, char *line)
{
	int	i;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	if (stock[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clean_stock(char *stock)
{
	int		i;
	char	*new_stock;
	int		j;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	if (stock[i] == '\n')
		i++;
	j = 0;
	while (stock[i + j])
		j++;
	new_stock = ft_calloc(sizeof(char), (j + 1));
	if (!new_stock)
		return (NULL);
	j = 0;
	while (stock[i + j])
	{
		new_stock[j] = stock[i + j];
		j++;
	}
	free(stock);
	return (new_stock);
}
