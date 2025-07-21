/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad.al-quraan <ahmad.al-quraan@learner.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:58:38 by ahmad.al-qura     #+#    #+#             */
/*   Updated: 2025/07/16 18:58:39 by ahmad.al-qura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	total_size(char **strs, int size, int sizeSep)
{
	int	total_size;
	int	i;
	int	j;
	int	cnt;

	total_size = 0;
	i = 0;
	while (i != size)
	{
		j = 0;
		cnt = 0;
		while (strs[i][j])
		{
			cnt += 1;
			j += 1;
		}
		total_size += cnt;
		total_size += sizeSep;
		i += 1;
	}
	total_size -= sizeSep;
	return (total_size);
}

int	length(char *str)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (str[i])
	{
		size += 1;
		i += 1;
	}
	return (size);
}

void	increase_sep(char *ret, int *idx, char *sep)
{
	int	j;

	j = 0;
	while (sep[j])
	{
		ret[*idx] = sep[j];
		*idx += 1;
		j += 1;
	}
}

void	solve(char **strs, int size, char *sep, char *ret)
{
	int	i;
	int	idx;
	int	j;

	i = 0;
	idx = 0;
	j = 0;
	while (i != size)
	{
		j = 0;
		while (strs[i][j])
		{
			ret[idx] = strs[i][j];
			idx += 1;
			j += 1;
		}
		j = 0;
		if (i != size - 1)
			increase_sep(ret, &idx, sep);
		i += 1;
	}
	ret[idx] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_sizee;
	char	*ret;

	if (!strs || !sep)
	{
		return (NULL);
	}
	if (size == 0)
	{
		ret = (char *)malloc(1);
		*ret = '\0';
		return (ret);
	}
	total_sizee = total_size(strs, size, length(sep));
	ret = (char *)malloc(sizeof(char) * total_sizee + 1);
	solve(strs, size, sep, ret);
	return (ret);
}
// main for testing
// int	main(void)
// {
// 	char	*arr1;
// 	char	*arr2;
// 	char	*arr3;
// 	char	**str;
// 	char	*sep;
//
// 	arr1 = "kMRjMcIFLpuchHsXAPmEmpCA";
// 	arr2 = "hi";
// 	arr3 = "welcome";
// 	str = malloc(1 * sizeof(char *));
// 	str[0] = arr1;
// 	str[1] = arr2;
// 	str[2] = arr3;
// 	sep = "coACpPBnFmccqqpH";
// 	printf("%s", ft_strjoin(1, str, sep));
// }
