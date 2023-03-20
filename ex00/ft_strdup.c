/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:39:33 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/19 20:22:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char			*dest;
	char			*_dest;
	unsigned int	len;

	len = ft_strlen(src);
	dest = (char *)malloc(len + 1);
	_dest = dest;
	if (dest)
	{
		while (1)
		{
			*dest = *src++;
			if (!*dest++)
				break ;
		}
	}
	return (_dest);
}
