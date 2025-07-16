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

int	total_size(int size, char **strs, int sizeSep)
{
	int	total_size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	total_size = 0;
	while (i != size)
	{
		while (strs[i][j])
		{
			total_size += 1;
			j += 1;
		}
		total_size += sizeSep;
		j = 0;
		i += 1;
	}
	total_size -= sizeSep;
	return (total_size);
}

void	save_in_array(char *ret, char sizeSep, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	j = 0;
	idx = 0;
	while (i != size)
	{
		while (strs[i][j])
		{
			ret[idx] = strs[i][j];
			idx += 1;
			j += 1;
		}
		j = 0;
		if (i != size - 1)
		{
			while (j != sizeSep)
			{
				ret[idx] = sep[j];
				idx += 1;
				j += 1;
			}
		}
		j = 0;
		i += 1;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		sizeSep;
	int		i;
	int		total_sizee;
	char	*ret;

	if (size == 0)
	{
		ret = (char *)malloc(1);
		*ret = '\0';
		return (ret);
	}
	sizeSep = 0;
	i = -1;
	while (sep[++i])
		sizeSep += 1;
	total_sizee = total_size(size, strs, sizeSep);
	ret = (char *)malloc(sizeof(char) * total_sizee);
	save_in_array(ret, sizeSep, size, strs, sep);
	return (ret);
}
// // main for testing
// int main() {
//   char *arr1 = "hello";
//   char *arr2 = "hi";
//   char *arr3 = "welcome";
//
//   char **str = malloc(3 * sizeof(char *));
//   str[0] = arr1;
//   str[1] = arr2;
//   str[2] = arr3;
//   char *sep = ", ";
//   printf("%s", ft_strjoin(0, str, sep));
// }
