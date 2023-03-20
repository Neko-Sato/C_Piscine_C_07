/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:24:30 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/20 05:09:00 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int nbr, char *base);
int		ft_strlduplicate(char *str);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	n;

	if (!ft_strlduplicate(base_from))
		return (NULL);
	return (ft_itoa_base(ft_atoi_base(nbr, base_from), base_to));
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

int	ft_atoi_base(char *str, char *base)
{
	int	sgin;
	int	result;
	int	base_length;
	int	temp;

	sgin = 1;
	result = 0;
	base_length = ft_strlduplicate(base);
	if (base_length <= 1)
		return (0);
	while ((0x08 < *str && *str < 0x0e) || *str == 0x20)
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sgin *= -1;
	while (*str)
	{
		temp = str_index(*str, base) - 1;
		if (temp < 0)
			return (0);
		result *= base_length;
		result += temp;
		str++;
	}
	return (sgin * result);
}

// #include <stdio.h>
// int	main(int argc, char *argv[])
// {
// 	printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
// }