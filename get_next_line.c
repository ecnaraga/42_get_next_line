/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:47:34 by galambey          #+#    #+#             */
/*   Updated: 2023/05/10 16:49:50 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*sauv;
	unsigned int	buffer_size;

	buffer_size = BUFFER_SIZE;
	if (!buffer_size || buffer_size == 0)
		return (NULL);
        
}

https://www.codequoi.com/variables-locales-globales-statiques-en-c/
https://openclassrooms.com/forum/sujet/comment-ca-fonctionne-12569
http://manpagesfr.free.fr/man/man2/read.2.html