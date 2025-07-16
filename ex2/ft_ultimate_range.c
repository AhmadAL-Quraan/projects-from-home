/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad.al-quraan <ahmad.al-quraan@learner.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:48:26 by ahmad.al-qura     #+#    #+#             */
/*   Updated: 2025/07/16 18:48:27 by ahmad.al-qura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	num;

	if (min >= max)
	{
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	num = min;
	while (i != max - min)
	{
		range[0][i] = num;
		i += 1;
		num += 1;
	}
	return (max - min);
}
