/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:35:18 by garance           #+#    #+#             */
/*   Updated: 2023/05/15 14:53:31 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_present_char(char *buffer, char c)
{
	int	i;

	i = 0;
	if (buffer)
	{
		while (buffer[i] && buffer[i] != c)
			i++;
		if (buffer[i] == c)
			return (i);
	}
	return (-1);
}

char	*ft_new_line(char *line, char *buffer, int i)
{
	char	*temp;

	temp = NULL;
	if (line)
	{
		temp = ft_strdup(line);
		if (!temp)
			return (NULL);
		free (line);
		line = ft_strjoin_mode(temp, buffer, i);
		free (temp);
	}
	else
		line = ft_strjoin_mode(line, buffer, i);
	if (!line)
		return (NULL);
	else
		return (line);
}

char	*ft_read_fd(char *save, char *line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		count;
	int		i;

	count = -1;
	i = -1;
	ft_bzero(save, BUFFER_SIZE + 1);
	while (i < 0 && count != 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (NULL);
		i = ft_present_char(buffer, '\n');
		if (!line && count == 0)
			return (NULL);
		line = ft_new_line(line, buffer, i);
		if (!line)
			return (NULL);
		if (i >= 0 && i < (int) ft_strlen(buffer))
			ft_strcpy(save, buffer + i + 1);
		if (i >= 0)
			return (line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		save[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 1000000 || fd < 0)
		return (NULL);
	line = NULL;
	if (save[0] && ft_present_char(save, '\n') >= 0)
	{
		line = ft_strjoin_mode(line, save, ft_present_char(save, '\n'));
		ft_strcpy(save, save + ft_present_char(save, '\n') + 1);
		return (line);
	}
	if (!save[0])
	{
		ft_bzero(save, BUFFER_SIZE + 1);
		return (ft_read_fd(save, line, fd));
	}
	if (save[0] && ft_present_char(save, '\n') == -1)
	{
		line = ft_strjoin_mode(line, save, -1);
		if (!line)
			return (NULL);
		return (ft_read_fd(save, line, fd));
	}
	return (NULL);
}
