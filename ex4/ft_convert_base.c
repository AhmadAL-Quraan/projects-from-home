/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad.al-quraan <ahmad.al-quraan@learner.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:48:29 by ahmad.al-qura     #+#    #+#             */
/*   Updated: 2025/07/17 17:48:30 by ahmad.al-qura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		lengthh(char *str);
int		powerr(int x, int y);
void	check_neg(char *arr, int *idx, int *size, int *swap_idx);
char	*swapp(char *arr, int swap_idx, int size, int neg);
int		check_base_validation(char *str);

int	check_inside_the_basee(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i += 1;
	}
	return (-2);
}

int	nbr_idx_inside_basee(int *first_idx, char *base_from, char *nbr, int *neg)
{
	int	idx;

	idx = 0;
	while (nbr[idx] == ' ' || (nbr[idx] >= 9 && nbr[idx] <= 13))
	{
		idx += 1;
	}
	while (nbr[idx] == '+' || nbr[idx] == '-')
	{
		if (nbr[idx] == '-')
			*neg *= -1;
		idx += 1;
	}
	while (nbr[idx] && check_inside_the_basee(base_from, nbr[idx]) != -2)
	{
		if (*first_idx == -1)
			*first_idx = idx;
		idx += 1;
	}
	if (check_inside_the_basee(base_from, nbr[idx - 1]) != -2)
		return (idx - 1);
	return (-1);
}

char	*convert_to_base_to(char *base_to, int converted, int neg)
{
	int		idx;
	int		swap_idx;
	int		size;
	char	*arr;

	idx = 0;
	swap_idx = 0;
	size = 0;
	arr = malloc((int)1e4);
	if (neg < 0)
		check_neg(arr, &idx, &size, &swap_idx);
	if (converted == 0)
	{
		arr[idx++] = base_to[0];
		size++;
	}
	while (converted > 0)
	{
		size += 1;
		arr[idx++] = base_to[converted % lengthh(base_to)];
		converted /= lengthh(base_to);
	}
	arr[idx] = '\0';
	return (swapp(arr, swap_idx, size, neg));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	neg;
	int	first_idx;
	int	where_to_set_last;
	int	result;
	int	to_the_power;

	if (!base_from || !base_to || !nbr)
		return (NULL);
	neg = 1;
	first_idx = -1;
	if (!check_base_validation(base_from) || !check_base_validation(base_to))
		return (NULL);
	where_to_set_last = nbr_idx_inside_basee(&first_idx, base_from, nbr, &neg);
	if (where_to_set_last == -1)
		return (NULL);
	result = 0;
	to_the_power = 0;
	while (where_to_set_last != first_idx - 1)
	{
		result += powerr(lengthh(base_from), to_the_power++)
			* check_inside_the_basee(base_from, nbr[where_to_set_last]);
		where_to_set_last -= 1;
	}
	return (convert_to_base_to(base_to, result, neg));
}
// int main(void) {
//   printf("%s", ft_convert_base("----7f3", "0123456789abcdef", "01"));
// }
