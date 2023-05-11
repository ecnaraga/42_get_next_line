/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:43:37 by galambey          #+#    #+#             */
/*   Updated: 2023/05/11 14:08:38 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	int		fd;
	char	*buffer;

	i = 0;
	fd = open("text.txt", O_RDONLY);///////////////////////// creer un fichier texte et le lie au file descriptor
	buffer = ft_get_next_line(fd);
	printf("retour get_next_line : '%s'\n", buffer);
	buffer = ft_get_next_line(fd);
	printf("retour get_next_line : '%s'\n", buffer);
	/*while(buffer[i])
	{
		printf("Appel %d/n", i++);
		buffer = ft_get_next_line(fd);
		printf("retour get_next_line : '%s'\n", buffer);
	}*/
	close(fd);
    return (0);
}