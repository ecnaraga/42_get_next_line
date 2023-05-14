/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:43:37 by galambey          #+#    #+#             */
/*   Updated: 2023/05/14 17:30:20 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/*
int	main(void) // appelle 2 x get_next_line
{
	int		i;
	size_t		fd;
	char	line[BUFFER_SIZE];
	int	count;

	i = 1;
	fd = open("text.txt", O_RDONLY);
	line = ft_get_next_line(fd);
	printf("Appel %d\n", i++);
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = ft_get_next_line(fd);
	printf("Appel %d\n", i++);
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	count = read(fd, line, BUFFER_SIZE);
	count = read(fd, line, BUFFER_SIZE);
	printf("line %d: %s\n", count, line);
	close(fd);
	return (0);
}
*/

int	main(void) //appelle get_next_line jusqu a la fin du fd
{
	int		i;
	int		fd;
	char	*line;

	i = 1;
	fd = open("text5.txt", O_RDONLY);///////////////////////// creer un fichier texte et le lie au file descriptor
	line = ft_get_next_line(fd);
	printf("Appel %d\n", i++);
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	while(line)
	{
		printf("Appel %d\n", i++);
		line = ft_get_next_line(fd);
		printf("retour get_next_line : '%s'\n\n", line);
		free (line);
	}
	close(fd);
    return (0);
}
/*
int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 1;
	fd = 0;
	line = ft_get_next_line(fd);
	printf("Appel %d\n", i++);
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	printf("Appel %d\n", i++);
	line = ft_get_next_line(fd);
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	close(fd);
    return (0);
}
*/