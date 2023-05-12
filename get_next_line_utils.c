/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:47:39 by galambey          #+#    #+#             */
/*   Updated: 2023/05/12 16:41:07 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
/*
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (dst == NULL && size == 0)
		return (ft_strlen(src) + size);
	len = ft_strlen(dst);
	if (len > size - 1 || size == 0)
		return (ft_strlen(src) + size);
	while (src[i] && len + i < size - 1)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (ft_strlen(src) + len);
}
*/
void	*ft_calloc(size_t nmemb, size_t size) // a voir
{
	void	*array;

	if (size != 0 && (nmemb > ((sizeof(char) * 2147483424) / size)))
		return (NULL);
	array = (void *)malloc(size * nmemb);
	if (!array)
		return (NULL);
	ft_bzero(array, (nmemb * size));
	return (array);
}

static void	ft_strcat(char *dst, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			len;
	char		*s;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		len = ft_strlen(s2);
	else if (!s2)
		len = ft_strlen(s1);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(sizeof(char) *(len + 1));
	if (!s)
		return (NULL);
	s[0] = '\0';
	if (s1)
		ft_strcat(s, s1);
	if (s2)
		ft_strcat(s, s2);
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}