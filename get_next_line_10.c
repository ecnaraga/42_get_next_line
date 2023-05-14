/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_10.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:35:18 by garance           #+#    #+#             */
/*   Updated: 2023/05/14 15:47:21 by garance          ###   ########.fr       */
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

/* *****************************************************************************
 * 
 * Description : Cherche dans une string un caractere et renvoie l index auquel
 *				 se trouve la premiere occurence.
 *
 * Valeur de retour :
 * => Retour = -1 : Le caractere est absent de la string ou le buffer n existe
 *					pas
 * => Retour >= 0 : Index + 1 dans la string auquel se trouve le caractere
 *
 * ************************************************************************* */

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

char	*ft_read_fd(char *save, char *line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		count;
	char	*temp;

	count = -1;
	temp = NULL;
	while (ft_present_char(line, '\n') < 0 && count != 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		count = read(fd, buffer, BUFFER_SIZE);
		if (!line && count == 0)
			return (NULL);
		if (line)
		{
			temp = ft_strdup(line);
			if (!temp)
				return (NULL);
			free (line);
			line = ft_strjoin_mode(temp, buffer, ft_present_char(buffer, '\n'));
			free (temp);
		}
		else
			line = ft_strjoin_mode(line, buffer, ft_present_char(buffer, '\n'));
		if (!line)
			return (NULL);
		if (ft_present_char(buffer, '\n') >= 0
			&& ft_present_char(buffer, '\n') < (int) ft_strlen(buffer))
			ft_strcpy(save, buffer + ft_present_char(buffer, '\n') + 1);
		if (ft_present_char(buffer, '\n') >= 0)
			return (line);
	}
	return (line);
}

/* *****************************************************************************
 * 
 * Description : 
 *				 
 *				- Cas 1 : Save n'est pas vide et contient un '\n'
 *              - Cas 2 : Save est vide
 *              - Cas 3 : Save n est pas vide et ne contient pas de '\n' 
 *
 * Valeur de retour :
 * => Retour Cas 1 : retourne les premiers caracteres de save jusqu'au '\n'
 *				     inclus (line), et on sauvegarde dans save plus que les
 *                   caracteres apres le '\n'
 * => Retour Cas 2 : 
 *
 * SIZE_MAX BUFFER_SIZE ASUS 8379436 > limite allocation memoire dans la stack c est pour ca que ca ne marche plus apres
 *
 * ************************************************************************* */

char	*ft_get_next_line(int fd) // question : si BUFFERSIZE = 0 + fd = 0, est ce que le programe doit demander a l u
{
	char			*line;
	static char		save[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0)
		return (0);
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
		ft_bzero(save, BUFFER_SIZE + 1);
		return (ft_read_fd(save, line, fd));
	}
	return (NULL);
}