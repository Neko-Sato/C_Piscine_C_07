/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:39:33 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/23 05:10:42 by hshimizu         ###   ########.fr       */
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
	dest = (char *)malloc((len + 1) * sizeof(char));
	_dest = dest;
	if (dest)
	{
		while (1)
		{
			*dest++ = *src;
			if (!*src++)
				break ;
		}
		*dest = '\0';
	}
	return (_dest);
}
