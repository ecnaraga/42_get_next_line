/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:47:39 by galambey          #+#    #+#             */
/*   Updated: 2023/05/11 15:15:30 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	i;

	if (size != 0 && (nmemb > ((sizeof(char) * 2147483424) / size)))
		return (NULL);
	array = (void *)malloc(size * nmemb);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		((unsigned char *)array)[i] = '\0';
		i++;
	}
	return (array);
}