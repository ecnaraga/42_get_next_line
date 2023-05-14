/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:17:59 by galambey          #+#    #+#             */
/*   Updated: 2023/05/13 14:47:05 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* *****************************************************************************
/* 
/* Description : Cherche dans une string un caractere et renvoie l index auquel
/*				 se trouve la premiere occurence.
/*
/* Valeur de retour :
/* => Retour = -1 : Le caractere est absent de la string ou le buffer n existe
/*					pas
/* => Retour >= 0 : Index dans la string auquel se trouve le caractere
/*
/* ************************************************************************* */

int	ft_present_char(char *buffer, char c)
{
	int	i;

	i = 0;
	if (buffer)
	{
		while (buffer && buffer[i] != c)
			i++;
		if (buffer[i] == c)
			return (i);
	}
	return (-1);
}

/* *****************************************************************************
/* 
/* Description : Lit le fd et, stocke dans line le buffer, tant que n'a pas
/*				 trouve '\n' dans le buffer ou que read n'a pas fini de lire le
/*				 fd (soit, count > 0),
/*				 PS : La memoire de buffer est initialisee avec des '\0', pour
/*				      avoir un '\0' a la fin du buffer apres passage de read 
/*
/* Valeur de retour :
/* => Retour = NULL : L'allocation de memoire de line a echouee
/* => Retour >= 0 : Index du buffer auquel se trouve un '\n'
/* => Retour >=  -1 : Read est arrive a la fin du fd, et la fin de ce dernier
/*					  s'il ne finit pas par un '\n' a ete stocke dans line.
/*					  PS : Si le fd se finit par un '\n', le buffer ne contient
/*					       que des '\0' et line est NULL
/*
/* ************************************************************************* */

int	ft_read_fd(char *line, char *buffer, int fd)
{
	int		i;
	int		count;
	char	*temp;

	temp == NULL;
	while (ft_present_char(buffer, '\n') < 0 && count != 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		count = read(fd, buffer, BUFFER_SIZE); // que se passe t il si count = -1 (retour erreur de read)?                                                                                           
		i = ft_present_char(buffer, '\n');
		if (i < 0)
		{
			if (line)
			{
				temp = line;
				line = ft_strjoin(temp, buffer);
				free(temp);
			}
			else
				line = ft_strjoin(temp, buffer);
			if (!line)
				return (NULL);
		}
	}
	return (i);
}

/* *****************************************************************************
/* 
/* Description : Cree la ligne a renvoyer ainsi que la sauvegarde
/*				 
/*				 
/*				 
/*				 
/*
/* Valeur de retour :
/* => Retour 
/* => Retour 
/* => Retour 
/*
/* ************************************************************************* */

char	*ft_new_line(char *sauv, char *line, char *buffer, int i)
{
	int		len;
	char	*temp;

	len = ft_strlen(buffer);
	if (!buffer && !sauv)
		return (NULL);
	if (sauv) //normalement line a cet endroit toujours nul et sauv ne contient pas de '\n'> a verifier
	{
		line = ft_strjoin(sauv, line);
		ft_bzero(sauv);
		ft_read_fd(line, buffer, fd);
	}
	if (line && buffer)
	{
		temp = line;
		line = ft_strjoin(temp, /*buffer jusqu au i*/);
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
	static char	*sauv[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = NULL;
	buffer = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
//if (fd) >>> secu a rajouter  + pour bonus 1024 fd max de 0 a 1023
	if (!sauv || ft_present_char(sauv, '\n') == -1)
	{
		i = ft_read_fd(line, buffer, fd); //>> voir cas ou i = -1
		return (ft_new_line(sauv, line, buffer, i));
//		if (line != NULL)
//			return (line);
	}
	else //	if (sauv && ft_present_char >= 0)
	{
		ft_strjoin(line, sauv jusqu qu i);
		if (!line)
			return (NULL);
		sauv[0] = '\0';
		ft_strcat(sauv, sauv + ft_present_char(sauv + i, '\n'));
		return (line);
	}
	return (ft_free_get_next_line(sauv, line));
}