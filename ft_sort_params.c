/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad.al-quraan <ahmad.al-quraan@learner.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 04:47:00 by ahmad.al-qura     #+#    #+#             */
/*   Updated: 2025/07/23 04:47:03 by ahmad.al-qura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i += 1;
	}
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	size;
	int	i;

	size = length(str1);
	if (length(str2) < size)
		size = length(str2);
	i = 0;
	while (i != size)
	{
		if (str1[i] > str2[i])
			return (-1);
		else if (str1[i] < str2[i])
			return (1);
		i += 1;
	}
	if (length(str1) == length(str2))
		return (0);
	if (length(str1) < length(str2))
		return (1);
	else
		return (-1);
}

void	heapify(char **arr, int n, int idx)
{
	char	*temp;

	if (idx * 2 + 1 < n && ft_strcmp(arr[idx], arr[idx * 2 + 1]) == 1)
	{
		temp = arr[idx];
		arr[idx] = arr[idx * 2 + 1];
		arr[idx * 2 + 1] = temp;
		heapify(arr, n, idx * 2 + 1);
	}
	if (idx * 2 + 2 < n && ft_strcmp(arr[idx], arr[idx * 2 + 2]) == 1)
	{
		temp = arr[idx];
		arr[idx] = arr[idx * 2 + 2];
		arr[idx * 2 + 2] = temp;
		heapify(arr, n, idx * 2 + 2);
	}
}

void	heap_sort(char **arr, int size)
{
	int		i;
	char	*temp;

	i = size / 2 - 1;
	while (i != -1)
	{
		heapify(arr, size, i);
		i--;
	}
	i = size - 1;
	while (i != -1)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
		i -= 1;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*new_array[(int)1e4];

	if (argc == 1)
	{
		return (0);
	}
	i = 0;
	while (argv[i + 1])
	{
		new_array[i] = argv[i + 1];
		i += 1;
	}
	new_array[i] = NULL;
	heap_sort(new_array, argc - 1);
	i = 0;
	while (new_array[i])
	{
		write(1, new_array[i], length(new_array[i]));
		write(1, "\n", 1);
		i += 1;
	}
}
