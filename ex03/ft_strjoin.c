/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:15:45 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/19 19:15:36 by hshimizu         ###   ########.fr       */
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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char			*result;
	unsigned int	len;
	int				i[3];

	len = 1 + ft_strlen(sep) * (size - 1);
	i[0] = 0;
	while (strs[i[0]])
		len += ft_strlen(strs[i[0]++]);
	result = (char *)malloc((len + 1) * sizeof(char));
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (strs[i[1]])
	{
		while (strs[i[1]][i[2]])
			result[i[0]++] = strs[i[1]][i[2]++];
		if (!strs[++i[1]])
			break ;
		i[2] = 0;
		while (sep[i[2]])
			result[i[0]++] = sep[i[2]++];
		i[2] = 0;
	}
	result[i[0]++] = '\0';
	return (result);
}
