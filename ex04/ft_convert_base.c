/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:24:30 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/23 06:48:23 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int nbr, char *base);
int		ft_strlduplicate(char *str);
int		digits_base(int nbr, int base);
char	*num_store(char *str, unsigned int nbr, unsigned int base,
			char *replace);
int		str_index(char c, char *str);
int		ft_abs(int n);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	*num;

	num = ft_atoi_base(nbr, base_from);
	if (!num)
		return (NULL);
	return (ft_itoa_base(*num, base_to));
}

int	*ft_atoi_base(char *str, char *base)
{
	int	*result;
	int	sign_nbr[2];
	int	base_length;
	int	temp;

	base_length = ft_strlduplicate(base);
	if (base_length <= 1)
		return (NULL);
	sign_nbr[0] = 1;
	sign_nbr[1] = 0;
	while ((0x08 < *str && *str < 0x0e) || *str == 0x20)
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign_nbr[0] *= -1;
	while (*str)
	{
		temp = str_index(*(str++), base) - 1;
		if (temp < 0)
			break ;
		sign_nbr[1] = sign_nbr[1] * base_length + temp;
	}
	result = (int *)malloc(sizeof(int));
	*result = sign_nbr[0] * sign_nbr[1];
	return (result);
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*result;
	char	*str;
	int		base_length;

	base_length = ft_strlduplicate(base);
	if (base_length <= 1)
		return (NULL);
	str = (char *)malloc((digits_base(ft_abs(nbr), base_length + (nbr < 0) + 1))
			* sizeof(char));
	result = str;
	if (nbr < 0)
		*(str++) = '-';
	nbr = ft_abs(nbr);
	if (nbr == 0)
		*(str++) = base[0];
	*num_store(str, nbr, base_length, base) = '\0';
	return (result);
}

// #include <stdio.h>

// int	main(int argc, char *argv[])
// {
// 	// printf("%s\n", ft_convert_base("350350", "0123456789", "()"));
// 	if (3 <= argc)
// 		printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
// }