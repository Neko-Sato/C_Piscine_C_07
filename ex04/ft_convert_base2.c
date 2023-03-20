/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:25:29 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/20 14:07:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlduplicate(char *str)
{
	unsigned int	i;
	char			*_str;

	i = 0;
	while (*str)
	{
		if (*str == '+' || *str == '-')
			return (0);
		_str = str;
		while (*_str++)
			if (*str == *_str)
				return (0);
		str++;
		i++;
	}
	return (i);
}

int	digits_base(int nbr, int base)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char	*num_store(char *result, unsigned int nbr, unsigned int base,
		char *replace)
{
	if (!nbr)
		return (result);
	result = num_store(result, nbr / base, base, replace);
	*result = *(replace + nbr % base);
	return (result + 1);
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*result;
	char	*_result;
	int		base_length;
	int		nbr_len;

	base_length = ft_strlduplicate(base);
	if (base_length <= 1)
		return (NULL);
	nbr_len = digits_base(nbr * (1 + -2 * (nbr < 0)), base_length);
	result = (char *)malloc((base_length + (nbr < 0) + 1) * sizeof(char));
	_result = result;
	if (nbr < 0)
	{
		*result++ = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		*result++ = base[0];
	*num_store(result, nbr, base_length, base) = '\0';
	return (_result);
}
