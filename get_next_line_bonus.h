/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:47:21 by galambey          #+#    #+#             */
/*   Updated: 2023/05/14 17:54:53 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*ft_get_next_line(int fd);
int		ft_present_char(char *buffer, char c);
char	*ft_new_line(char *line, char *buffer, int i);
char	*ft_read_fd(char *save, char *line, int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin_mode(char const *s1, char const *s2, int i);
void	ft_bzero(void *s, size_t n);
void	ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s);

#endif