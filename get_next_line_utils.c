/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:47:39 by galambey          #+#    #+#             */
/*   Updated: 2023/05/14 17:35:26 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *s)
{
	char		*cpy;
	int			i;

	i = 0;
	cpy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (cpy == NULL)
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (src)
	{	
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
}

char	*ft_strjoin_mode(char const *s1, char const *s2, int i)
{
	int			len;
	char		*s;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && i == -1)
		len = ft_strlen(s2);
	else if (!s1)
		len = i + 1;
	else if (!s2)
		len = ft_strlen(s1);
	else if (i == -1)
		len = ft_strlen(s1) + ft_strlen(s2);
	else
		len = ft_strlen(s1) + i + 1;
	s = (char *)malloc(sizeof(char) *(len + 1));
	if (!s)
		return (NULL);
	s[0] = '\0';
	if (s1)
		ft_strlcat(s, s1, ft_strlen(s1) + 1);
	if (s2)
		ft_strlcat(s, s2, len + 1);
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
