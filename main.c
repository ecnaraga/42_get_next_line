/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:43:37 by galambey          #+#    #+#             */
/*   Updated: 2023/05/12 14:21:13 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	size_t		fd;
	char	buffer[BUFFER_SIZE];
	int	count;

	i = 0;
	fd = open("text_copy.txt", O_CREAT | O_RDONLY);
	count = read(fd, buffer, BUFFER_SIZE);
	count = read(fd, buffer, BUFFER_SIZE);
	printf("buffer %d: %s\n", count, buffer);
	close(fd);
	return (0);
}

/*
int	main(void)
{
	int		i;
	int		fd;
	char	*buffer;

	i = 0;
	fd = open("text.txt", O_RDONLY);///////////////////////// creer un fichier texte et le lie au file descriptor
	buffer = ft_get_next_line(fd);
	while(buffer)
	{
		printf("Appel %d/n", i++);
		buffer = ft_get_next_line(fd);
		printf("retour get_next_line : '%s'\n", buffer);
	}
	close(fd);
    return (0);
}
*/