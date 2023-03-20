/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:25:29 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/21 01:16:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	i = 0;
	if (nbr != 0)
		while (nbr)
			nbr /= base + 0 * i++;
	else
		i = 1;
	return (i);
}

char	*num_store(char *str, unsigned int nbr, unsigned int base,
		char *replace)
{
	if (!nbr)
		return (str);
	str = num_store(str, nbr / base, base, replace);
	*str = *(replace + nbr % base);
	return (str + 1);
}

int	str_index(char c, char *str)
{
	char	*_str;

	_str = str;
	while (*str)
		if (*(str++) == c)
			return (str - _str);
	return (-1);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
