/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:47:34 by galambey          #+#    #+#             */
/*   Updated: 2023/05/11 16:53:38 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_present_char(char *buffer)
{
	int		i;

	i = 0;
	while (buffer && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (i);
	else if (buffer[i] == '\0')
		return (-1);
	else
		return (-2);
}

char	*ft_new_line(char *sauv, char *line, char *buffer)
{
	int		i;
	size_t	len;
	int		count;

	i = -3;
	count = -3;
	while (i < 0 && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		i = ft_present_char(buffer);
	}
	if (i >= 0) // a trouve un \n
	{
		line = calloc(i + 2, sizeof(char));
		if (!line)
			return (NULL);
		sauv = calloc((len - i) * sizeof(char));
		if (!sauv)
			return (NULL);
		ft_strlcpy(line, buffer, i + 2);
		ft_strlcpy(sauv, buffer + i + 1, len - i);
		return (line);
		if (count == 0)
	}
	if count == 0 i == 0
}

char	*ft_get_next_line(int fd)
{
	static char	*sauv;
	char		*buffer;
	char		*line;

	if (BUFFER_SIZE < 0)
		return (NULL);
	if (!sauv)
	{
		ft_new_line(sauv, line, buffer);
		return (line);
	}
	else creer newline
	{

	}
	return (line);
}

/* essai 2
{
	static char		*sauv;
	char			*buf;
	char			buffer[BUFFER_SIZE];
	unsigned int	count;
	unsigned int	i;

	i = 0;
	if (BUFFER_SIZE < 0)
		return (NULL);
	if (!sauv)
	{
		printf("test0\n");
		count = read(fd, buffer, BUFFER_SIZE);
		printf("buffer %s \n", buffer);
		while (i < count && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
		{
			sauv = malloc(sizeof(char) * (ft_strlen(buffer) - i)); // -1 x \n qu on va renvoyer et +1 x le \0 qu on rajoute a la fin d une string
			if (!sauv)
				return (NULL);
			buf = malloc(sizeof(char) * (i + 2));
			if (!buf)
			return (NULL);
			ft_strlcpy(sauv, buffer, ft_strlen(buffer) - i);
			ft_strlcpy(buf, buffer, i + 2);
			printf("buf %s\n", buf);
			return (buf);
		}
		else if (buffer[i])
			{
				
			}
	}
	printf("test3\n");
	return (NULL);
}
*/
/* essai 1
	static char		*sauv;
	char			*buffer;
	char			*line;
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	if (BUFFER_SIZE > 0)
		return (NULL);
	buffer = NULL;
	i = 0;
	j = 0;
	if (sauv != NULL)
	{
		copier sauv dans buffer puis de buffer dans line,
			free sauv et re malloc puis copier de buffer dans sauv
	}
	count = read(fd, buffer, BUFFER_SIZE);
	while (count > 0 && buffer[i])
	{
		line[j++] = buffer[i++];
		if (buffer[i] == '\n')
		{
			line[j++] = buffer[i++];
			if (buffer[i])
			{
				sauv = (char *)malloc(sizeof(char) * ft_strlen(buffer + i) + 1);
				if (sauv == NULL)
					return (NULL);
				ft_strlcpy(sauv, buffer + i, ft_strlen(buffer + i) + 1);
			}
			return (line);
		}
		else if (buffer[i] == '\0')
		{
			read(fd, buffer, BUFFER_SIZE);
			i = 0;
		}
	}
}

https://www.codequoi.com/variables-locales-globales-statiques-en-c/
https://openclassrooms.com/forum/sujet/comment-ca-fonctionne-12569
http://manpagesfr.free.fr/man/man2/read.2.html
*/