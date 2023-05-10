/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:47:34 by galambey          #+#    #+#             */
/*   Updated: 2023/05/10 20:55:00 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
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
		copier sauv dans buffer puis de buffer dans line, free sauv et re malloc puis copier de buffer dans sauv
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