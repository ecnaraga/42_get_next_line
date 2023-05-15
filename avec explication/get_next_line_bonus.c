/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:35:18 by garance           #+#    #+#             */
/*   Updated: 2023/05/15 14:34:32 by galambey         ###   ########.fr       */
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

/* *****************************************************************************
 * 
 * Description : Cree la ligne a retourner, grace a une allocation de memoire
 *				 dynamique.
 *				 Si la ligne n est pas vide (elle ne contiendra jamais de '\n'
 *				 ici), elle ajoute le buffer jusqu au '\n' inclus, sinon elle
 *				 copiera le buffer jusqu'au '\n' inclus directement. Si le buffer
 *				 ne contient pas de '\n', elle l'ajoutera/copiera integralement.
 *				 => i : index du buffer ou se trouve le '\n' ou  -1 si pas de 
 *				 		'\n' dans le buffer
 *
 * Valeur de retour :
 * => Retour = NULL : L allocation dynamique a echouee
 *
 * => Retour = ligne : La ligne cree
 *
 * ************************************************************************* */

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

/* *****************************************************************************
 * 
 * Description : Lit en boucle le fd jusqu'a ce qu'il trouve un '\n' ou qu il
 *				 arrive a la fin du fd, et stocke au fur et a mesure dans line
 *				 le buffer jusqu'au 1er '\n' s'il y en a un de present.
 *				 Stocke, si besoin dans save, le reste du buffer(apres le 1er
 *				 '\n' trouve).
 *				 ps : save et buffer sont initialise avec ft_bzero pour pouvoir
 *				      arreter la lecture au '\0'.
 *
 * Valeur de retour :
 * => Retour = NULL : L allocation dynamique a echouee. Si l allocation a echouee
 *					  dans ft_new_line, line est egal a NULL et la fonction
 *					  renverra NULL.
 *					  Ou fin du fichier : il n y avait rien dans save, donc line
 *					  est NULL et read a deja lu tout le fd soit count = 0
 *
 * => Retour = ligne : La ligne cree que doit renvoyer get_next_line
 *
 * ************************************************************************* */

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

/* *****************************************************************************
 * 
 * Description : Renvoie le contenu d un fd, ligne par ligne avec le retour a la
 *				 ligne. Des appels successifs permettent donc de lire la totalite
 *				 du fd.
 *				 Si le BUFFER_SIZE n'est pas defini lors de la compilation, il
 *				 sera initialise par defaut a 50 caracteres.
 *				 Elle traite les 3 cas suivants :
 *				- Cas 1 : Save n'est pas vide et contient un '\n' : retourne les
 *              		  premiers caracteres de save jusqu'au '\n' inclus (line)
 *              		  et stocke si besoin dans save plus que les caracteres
 *              		  apres le 1er '\n'
 *              - Cas 2 : Save est vide : Fait appel a ft_read_fd et retourne la
 *              		  prochaine ligne du fd et stocke dans save si besoin
 *              - Cas 3 : Save n est pas vide et ne contient pas de '\n' > Fait
 *              		  appel a ft_read_fd et retourne la prochaine ligne du 
 *              		  fd et stocke dans save si besoin
 *
 * Valeur de retour :
 * => Retour = NULL : Soit une allocation de memoire a echouee, soit on est
 *				      arrive a la fin du fd, soit BUFFER_SIZE = 0;
 * => Retour = line
 *
 * SIZE_MAX BUFFER_SIZE ASUS 8379436 > limite allocation memoire dans la stack 
 c est pour ca que ca ne marche plus apres
 *
 * ************************************************************************* */

char	*get_next_line(int fd)
{
	char			*line;
	static char		save[1024][BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 1000000 || fd < 0)
		return (NULL);
	line = NULL;
	if (save[fd][0] && ft_present_char(save[fd], '\n') >= 0)
	{
		line = ft_strjoin_mode(line, save[fd], ft_present_char(save[fd], '\n'));
		ft_strcpy(save[fd], save[fd] + ft_present_char(save[fd], '\n') + 1);
		return (line);
	}
	if (!save[fd][0])
	{
		ft_bzero(save[fd], BUFFER_SIZE + 1);
		return (ft_read_fd(save[fd], line, fd));
	}
	if (save[fd][0] && ft_present_char(save[fd], '\n') == -1)
	{
		line = ft_strjoin_mode(line, save[fd], -1);
		if (!line)
			return (NULL);
		return (ft_read_fd(save[fd], line, fd));
	}
	return (NULL);
}
