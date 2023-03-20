/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:15:45 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/21 01:21:38 by hshimizu         ###   ########.fr       */
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

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*_dest;

	_dest = dest;
	while (n--)
	{
		*dest = *src;
		dest++;
		src += *src != '\0';
	}
	return (_dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char			*result;
	char			*_result;
	unsigned int	len;
	unsigned int	sep_len;
	int				i;

	sep_len = ft_strlen(sep);
	len = (1 < size) * (size - 1) * sep_len + 1;
	i = 0;
	while (i < size)
		len += ft_strlen(*(strs + i++));
	result = (char *)malloc(len * sizeof(char));
	_result = result;
	i = 0;
	while (i < size)
	{
		len = ft_strlen(*(strs + i));
		result = ft_strncpy(result, *(strs + i), len) + len;
		if (++i >= size)
			break ;
		result = ft_strncpy(result, sep, sep_len) + sep_len;
	}
	*result = '\0';
	return (_result);
}
