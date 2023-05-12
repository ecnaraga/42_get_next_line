/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_essai 4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:17:59 by galambey          #+#    #+#             */
/*   Updated: 2023/05/12 11:23:50 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_present_char(char *buffer)
{
	int	i;

	i = 0;
	while (buffer && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (i);
	else
		return (-1);
}

int	ft_read_fd(char *buffer, int fd)
{
	int	i;
	int	count;

	i = -1;
	count = -1;
	while (i < 0 && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		i = ft_present_char(buffer);
	}
	return (i);
}

char	*ft_new_line(char *sauv, char *line, char *buffer, int i);
{
	if (!buffer && !sauv)
		return (NULL);
	line = calloc(i + 2, sizeof(char)); // +1 x /n et +1 / \0
	if (!line)
		return (NULL);
	sauv = calloc((len - i) * sizeof(char)); // -1 x /n et +1 x \0 >> revoir cas ou sauv n est pas null
	if (!sauv)
		return (NULL);
	ft_strlcpy(line, buffer, i + 2);
	ft_strlcpy(sauv, buffer + i + 1, len - i);
	return (line);
}

char	*ft_get_next_line(int fd)
{
	static char	*sauv;
	char		*buffer;
	char		*line;
	int			i;

	if (BUFFER_SIZE < 0)
		return (NULL);
	if (!sauv)
	{
		i = ft_read_fd(buffer, fd); //>> voir cas ou i = -1
		ft_new_line(sauv, line, buffer, i);
		if (line != NULL)
			return (line);
		else
			free avant de return null
	}
	if (sauv && ft_present_char >= 0)
	{
		buffer = calloc((ft_strlen(sauv) + 1) * sizeof(char));
		free(sauv);
		ft_new_line(sauv, line, buffer, ft_present_char(buffer));
		if (line != NULL)
		{
			free(buffer);
			return (line);
		}
		return (NULL)
	}
	if (sauv && ft_present char == 0)
	{
		i = ft_read_fd(buffer, fd);
		//ft_new line qui doit gerer cas ou sauv n est pas null
		return (line);
	}
}