/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:17:59 by galambey          #+#    #+#             */
/*   Updated: 2023/05/13 16:58:02 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* *****************************************************************************
 * 
 * Description : Cherche dans une string un caractere et renvoie l index auquel
 *				 se trouve la premiere occurence.
 *
 * Valeur de retour :
 * => Retour = 0 : Le caractere est absent de la string ou le buffer n existe
 *					pas
 * => Retour > 0 : Index + 1 dans la string auquel se trouve le caractere
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
			return (i + 1);
	}
	return (0);
}

/* *****************************************************************************
 * 
 * Description : Lit le fd et, stocke dans line le buffer, tant que n'a pas
 *				 trouve '\n' dans le buffer ou que read n'a pas fini de lire le
 *				 fd (soit, count > 0),
 *				 PS : La memoire de buffer est initialisee avec des '\0', pour
 *				      avoir un '\0' a la fin du buffer apres passage de read 
 *
 * Valeur de retour :
 * => Retour = 0 : L'allocation de memoire de line a echouee
 * => Retour > 0 : Index + 1 du buffer auquel se trouve un '\n'
 * => Retour >=  0 : Read est arrive a la fin du fd, et la fin de ce dernier
 *					  s'il ne finit pas par un '\n' a ete stocke dans line.
 *					  PS : Si le fd se finit par un '\n', le buffer ne contient
 *					       que des '\0' et line est NULL
 *
 * ************************************************************************* */

int	ft_read_fd(char *line, char *buffer, int fd)
{
	int		i;
	int		count;
	char	*temp;

	temp = NULL;
	ft_bzero(buffer, BUFFER_SIZE + 1);
	count = read(fd, buffer, BUFFER_SIZE);
	while (ft_present_char(buffer, '\n') <= 0 && count != 0)
	{
		i = ft_present_char(buffer, '\n');
		if (i < 0)
		{
			if (line)
			{
				temp = line;
				line = ft_strjoin_mode(temp, buffer, 0);
				free(temp);
			}
			else
				line = ft_strjoin_mode(temp, buffer, 0);
			if (!line)
				return (0);
			ft_bzero(buffer, BUFFER_SIZE + 1);
			count = read(fd, buffer, BUFFER_SIZE); // que se passe t il si count = -1 (retour erreur de read)?                                                                                           
			i = ft_present_char(buffer, '\n');
		}
	}
	return (i);
}

/* *****************************************************************************
 * 
 * Description : Cree la ligne a renvoyer ainsi que la sauvegarde
 *				 
 *				 
 *				 
 *				 
 *
 * Valeur de retour :
 * => Retour 
 * => Retour 
 * => Retour 
 *
 * ************************************************************************* */

char	*ft_new_line(char *sauv, char *line, char *buffer, int i, int fd)
{
	int		len;
	char	*temp;

	len = ft_strlen(buffer);
	if (!buffer && !sauv)
		return (NULL);
	if (sauv) //normalement line a cet endroit toujours nul et sauv ne contient pas de '\n'> a verifier
	{
		line = ft_strjoin_mode(sauv, line, 0);
		ft_bzero(sauv, BUFFER_SIZE + 1);
		ft_read_fd(line, buffer, fd);
	}
	if (line && buffer) //
	{
		temp = line;
		line = ft_strjoin_mode(temp, buffer, ft_present_char(buffer, '\n'));
		free(temp);
		ft_strlcat(sauv, buffer + i + 1, len - i); // qd i = -1 que se pasee t il?
	}
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
	static char	sauv[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
//if (fd) >>> secu a rajouter  + pour bonus 1024 fd max de 0 a 1023
	if (!sauv[0] || ft_present_char(sauv, '\n') == 0)
		return (ft_new_line(sauv, line, buffer, ft_read_fd(line, buffer, fd), fd));
	else if (sauv[0] && ft_present_char(sauv, '\n') >= 0)
	{
		ft_strjoin_mode(line, sauv, ft_present_char(sauv, '\n'));
		if (!line)
			return (NULL);
		sauv[0] = '\0';
		ft_strcat(sauv, sauv + ft_present_char(sauv + i, '\n'));
		return (line);
	}
	return (ft_free_get_next_line(sauv, line));
}