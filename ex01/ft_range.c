/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:18:23 by hshimizu          #+#    #+#             */
/*   Updated: 2023/03/19 20:20:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	*_range;

	if (min >= max)
		return (NULL);
	range = (int *)malloc((max - min) * sizeof(int));
	_range = range;
	while (min < max)
		*range++ = min++;
	return (_range);
}
