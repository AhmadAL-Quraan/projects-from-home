/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad.al-quraan <ahmad.al-quraan@learner.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:06:30 by ahmad.al-qura     #+#    #+#             */
/*   Updated: 2025/07/17 19:06:32 by ahmad.al-qura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	powerr(int x, int y)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (i != y)
	{
		result *= x;
		i += 1;
	}
	return (result);
}

int	lengthh(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i += 1;
	}
	return (i);
}

char	*swapp(char *arr, int swap_idx, int size, int neg)
{
	char	temp;

	if (neg < 0)
		size += 1;
	while (swap_idx != size / 2)
	{
		temp = arr[swap_idx];
		arr[swap_idx] = arr[size - swap_idx - 1];
		arr[size - swap_idx++ - 1] = temp;
	}
	return (arr);
}

void	check_neg(char *arr, int *idx, int *size, int *swap_idx)
{
	arr[0] = '-';
	*idx = 1;
	*size = 1;
	*swap_idx = 1;
}

int	check_base_validation(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || (str[i] >= 9 && str[i] <= 13))
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j += 1;
		}
		i += 1;
	}
	if (i == 1 || i == 0)
	{
		return (0);
	}
	return (1);
}
