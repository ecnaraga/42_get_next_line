/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:43:37 by galambey          #+#    #+#             */
/*   Updated: 2023/05/29 15:41:36 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>
// MAIN QUI FAIT 2 APPELS GET_NEXT_LINE

// int	main(void) // appelle 2 x get_next_line
// {
// 	int		i;
// 	size_t		fd;
// 	char		*line;

// 	i = 1;
// 	fd = 0;
// 	//fd = open("text.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("Appel %d\n", i++);
// 	printf("retour get_next_line : '%s'\n\n", line);
// 	free (line);
// 	line = get_next_line(fd);
// 	printf("Appel %d\n", i++);
// 	printf("retour get_next_line : '%s'\n\n", line);
// 	free (line);
// 	close(fd);
// 	return (0);
// }
// 
// MAIN QUI LIT FD JUSQU A LA FIN

// int	main(void) //appelle get_next_line jusqu a la fin du fd
// {
// 	int		i;
// 	int		fd;
// 	char	*line;

// 	i = 1;
// 	fd = open("text0.txt", O_RDONLY);///////////////////////// creer un fichier texte et le lie au file descriptor
// 	line = get_next_line(fd);
// 	printf("Appel %d\n", i++);
// 	printf("retour get_next_line : '%s'\n\n", line);
// 	free (line);
// 	while(line)
// 	{
// 		printf("Appel %d\n", i++);
// 		line = get_next_line(fd);
// 		printf("retour get_next_line : '%s'\n\n", line);
// 		free (line);
// 	}
// 	close(fd);
// 	i = 1;
// 	fd = open("text0bis.txt", O_RDONLY);///////////////////////// creer un fichier texte et le lie au file descriptor
// 	line = get_next_line(fd);
// 	printf("Appel %d\n", i++);
// 	printf("retour get_next_line : '%s'\n\n", line);
// 	free (line);
// 	while(line)
// 	{
// 		printf("Appel %d\n", i++);
// 		line = get_next_line(fd);
// 		printf("retour get_next_line : '%s'\n\n", line);
// 		free (line);
// 	}
// 	close(fd);
// 	i = 1;
// 	fd = open("text0ter.txt", O_RDONLY);///////////////////////// creer un fichier texte et le lie au file descriptor
// 	line = get_next_line(fd);
// 	printf("Appel %d\n", i++);
// 	printf("retour get_next_line : '%s'\n\n", line);
// 	free (line);
// 	while(line)
// 	{
// 		printf("Appel %d\n", i++);
// 		line = get_next_line(fd);
// 		printf("retour get_next_line : '%s'\n\n", line);
// 		free (line);
// 	}
// 	close(fd);
// 	i = 1;
// 	fd = open("text1.txt", O_RDONLY);///////////////////////// creer un fichier texte et le lie au file descriptor
// 	line = get_next_line(fd);
// 	printf("Appel %d\n", i++);
// 	printf("retour get_next_line : '%s'\n\n", line);
// 	free (line);
// 	while(line)
// 	{
// 		printf("Appel %d\n", i++);
// 		line = get_next_line(fd);
// 		printf("retour get_next_line : '%s'\n\n", line);
// 		free (line);
// 	}
// 	close(fd);
// 	i = 1;
// 	fd = open("text2.txt", O_RDONLY);///////////////////////// creer un fichier texte et le lie au file descriptor
// 	line = get_next_line(fd);
// 	printf("Appel %d\n", i++);
// 	printf("retour get_next_line : '%s'\n\n", line);
// 	free (line);
// 	while(line)
// 	{
// 		printf("Appel %d\n", i++);
// 		line = get_next_line(fd);
// 		printf("retour get_next_line : '%s'\n\n", line);
// 		free (line);
// 	}
// 	close(fd);
// 	i = 1;
// 	fd = open("text3.txt", O_RDONLY);///////////////////////// creer un fichier texte et le lie au file descriptor
// 	line = get_next_line(fd);
// 	printf("Appel %d\n", i++);
// 	printf("retour get_next_line : '%s'\n\n", line);
// 	free (line);
// 	while(line)
// 	{
// 		printf("Appel %d\n", i++);
// 		line = get_next_line(fd);
// 		printf("retour get_next_line : '%s'\n\n", line);
// 		free (line);
// 	}
// 	close(fd);
// 	i = 1;
// 	fd = open("text4.txt", O_RDONLY);///////////////////////// creer un fichier texte et le lie au file descriptor
// 	line = get_next_line(fd);
// 	printf("Appel %d\n", i++);
// 	printf("retour get_next_line : '%s'\n\n", line);
// 	free (line);
// 	while(line)
// 	{
// 		printf("Appel %d\n", i++);
// 		line = get_next_line(fd);
// 		printf("retour get_next_line : '%s'\n\n", line);
// 		free (line);
// 	}
// 	close(fd);
// 	i = 1;
// 	fd = open("text5.txt", O_RDONLY);///////////////////////// creer un fichier texte et le lie au file descriptor
// 	line = get_next_line(fd);
// 	printf("Appel %d\n", i++);
// 	printf("retour get_next_line : '%s'\n\n", line);
// 	free (line);
// 	while(line)
// 	{
// 		printf("Appel %d\n", i++);
// 		line = get_next_line(fd);
// 		printf("retour get_next_line : '%s'\n\n", line);
// 		free (line);
// 	}
// 	close(fd);
//     return (0);
// }

// MAIN AVEC FD = 0 ET 2 APPELS DE GET_NEXT_LINE
/*
int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 1;
	fd = 0;
	line = get_next_line(fd);
	printf("Appel %d\n", i++);
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	printf("Appel %d\n", i++);
	line = get_next_line(fd);
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	close(fd);
    return (0);
}
*/

//**********************BONUS*************************

// MAIN BONUS

int	main(void)
{
	size_t		fd0;
	size_t		fd1;
	size_t		fd2;
	size_t		fd3;
	size_t		fd4;
	size_t		fd5;
	size_t		fd6;
	size_t		fd7;
	char		*line;

	fd0 = open("text0.txt", O_RDONLY);
	fd1 = open("text6.txt", O_RDONLY);
	fd2 = open("text7.txt", O_RDONLY);
	fd3 = open("text8.txt", O_RDONLY);
	fd4 = open("text9.txt", O_RDONLY);
	fd5 = open("text10.txt", O_RDONLY);
	fd6 = 0;
	fd7 = open("text0ter.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("Appel fd1\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd0);
	printf("Appel fd0\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd7);
	printf("Appel fd7\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd2);
	printf("Appel fd2\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd3);
	printf("Appel fd3\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd7);
	printf("Appel fd7\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd4);
	printf("Appel fd4\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd5);
	printf("Appel fd5\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd5);
	printf("Appel fd5\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd2);
	printf("Appel fd2\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd4);
	printf("Appel fd4\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd1);
	printf("Appel fd1\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd1);
	printf("Appel fd1\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	printf("Appel fd6 = 0 : Entree standard\n");
	line = get_next_line(fd6);
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd2);
	printf("Appel fd2\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd3);
	printf("Appel fd3\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd3);
	printf("Appel fd3\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd4);
	printf("Appel fd4\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("Appel fd2\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd1);
	printf("Appel fd1\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free(line);
	line = get_next_line(fd4);
	printf("Appel fd4\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free(line);
	line = get_next_line(fd1);
	printf("Appel fd1\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd1);
	printf("Appel fd1\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd0);
	printf("Appel fd0\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd2);
	printf("Appel fd2\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd1);
	printf("Appel fd1\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd4);
	printf("Appel fd4\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free(line);
	line = get_next_line(fd1);
	printf("Appel fd1\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd2);
	printf("Appel fd2\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd1);
	printf("Appel fd1\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free (line);
	line = get_next_line(fd4);
	printf("Appel fd4\n");
	printf("retour get_next_line : '%s'\n\n", line);
	free(line);
	close(fd0);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);
	close(fd7);
	return (0);
}

