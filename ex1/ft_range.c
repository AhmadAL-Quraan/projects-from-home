/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad.al-quraan <ahmad.al-quraan@learner.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:43:57 by ahmad.al-qura     #+#    #+#             */
/*   Updated: 2025/07/16 18:43:58 by ahmad.al-qura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;
	int	num;

	if (min >= max)
	{
		return (0);
	}
	ptr = (int *)malloc(sizeof(int) * (max - min));
	num = min;
	i = 0;
	while (i != max - min)
	{
		ptr[i] = num;
		i += 1;
		num += 1;
	}
	return (ptr);
}
