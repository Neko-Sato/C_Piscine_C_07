/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:15:45 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/19 16:34:54 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *result;
	int len;
	char **_strs;
	char *_str;
	char *_sep;
	char *_result;

	len = (size - 1) * ft_strlen(sep);
	_str = str;
	while (*strs)
		len += ft_strlen(*strs++);
	str = _str;
	result = (char *)malloc((len + 1) * sizeof(char));
	_result = result;
	while (*strs)
	{
		_str = *strs;
		while (**strs)
			*result++ = *(*strs)++;
		*strs = _str;
		strs++;
		if (!*strs)
			break ;
		_sep = sep;
		while (*sep)
			*result++ = *sep++;
		sep = _sep;
	}
	strs = _strs;
	result = '\0';
	return (_result);
}

int main(){}