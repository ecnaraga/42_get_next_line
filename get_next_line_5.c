/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:17:59 by galambey          #+#    #+#             */
/*   Updated: 2023/05/12 14:59:37 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_present_char(char *buffer)
{
	int	i;

	i = 0;
	if (buffer)
	{
		while (buffer && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
			return (i);
	}
	return (-1); 
}

int	ft_read_fd(, char *buffer, int fd)
{
	int	i;
	int	count;
	char *temp

	i = -1;
	count = -1;
	while (i < 0 && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		i = ft_present_char(buffer);
	}
	return (i);
}

char	*ft_new_line(char *sauv, char *line, char *buffer, int i)
{
	int	len;
	
	len = ft_strlen(buffer);
	if (!buffer && !sauv)
		return (NULL);
	line = calloc(i + 2 + ft_strlen(sauv), sizeof(char)); // +1 x /n et +1 x \0 et ft_strlen(sauv) > si n existe pas ou vide est egal a 0
	if (!line)
		return (NULL);
	if (sauv)
	{
		ft_strlcat(line, sauv, ft_strlen(sauv) + 1);
		free(sauv);
	}
	ft_strlcat(line, buffer, i + 2); // > comment se comporte strlcat si buffer n existe pas?
	sauv = calloc(len - i, sizeof(char)); // -1 x /n et +1 x \0 >> revoir cas ou len - i < 0 ou = 0
	if (!sauv)
		return (NULL);
	ft_strlcat(sauv, buffer + i + 1, len - i);
	return (line);
}

char	*ft_free_get_next_line(char *sauv, char *line)
{
	if (line)
		free (line);
	if (sauv)
		free (sauv);
	return (NULL);
}

char	*ft_get_next_line(int fd)
{
	static char	*sauv;
	char		buffer[BUFFER_SIZE];
	char		*line;
	int			i;

	line = NULL;
	buffer = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!sauv || ft_present_char(sauv) == -1)
	{
		i = ft_read_fd(buffer, fd); //>> voir cas ou i = -1
		ft_new_line(sauv, line, buffer, i);
		if (line != NULL)
			return (line);
	}
	else //	if (sauv && ft_present_char >= 0)
	{
/*		buffer = calloc((ft_strlen(sauv) + 1), sizeof(char));
		free(sauv);
		ft_new_line(sauv, line, buffer, ft_present_char(buffer));
		free(buffer);
		if (line != NULL)
			return (line);
*/	}
	return (ft_free_get_next_line(sauv, line));
}