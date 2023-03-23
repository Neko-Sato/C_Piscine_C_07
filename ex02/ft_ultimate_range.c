/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:36:38 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/23 21:56:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;

	len = max - min;
	if (len < 1)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(len * sizeof(int));
	if (!*range)
		return (-1);
	while (min < max)
		*((*range)++) = min++;
	*range -= len;
	return (len);
}