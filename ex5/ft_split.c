/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad.al-quraan <ahmad.al-quraan@learner.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:41:25 by ahmad.al-qura     #+#    #+#             */
/*   Updated: 2025/07/19 20:41:26 by ahmad.al-qura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	check(char str, char *charset)
{
	int	j;
	int	exist;

	j = 0;
	exist = 0;
	while (j != lengthh(charset))
	{
		if (str == charset[j])
		{
			exist = 1;
			break ;
		}
		j += 1;
	}
	return (exist);
}

void	make_malloc(int idx, char *arr, char **ptr, int *cnt_char)
{
	int	k;

	ptr[idx] = (char *)malloc(*cnt_char + 1);
	k = 0;
	while (k != *cnt_char)
	{
		ptr[idx][k] = arr[k];
		k += 1;
	}
	ptr[idx][k] = '\0';
	*cnt_char = 0;
}

char	**mshan_allah(char **ptr)
{
	return (ptr);
}

char	**ft_split(char *str, char *charset)
{
	char	*ptr[(int)1e3];
	char	arr[(int)1e4];
	int		i;
	int		cnt_char;
	int		idx;

	if (!str || !charset)
		return (NULL);
	i = -1;
	cnt_char = 0;
	idx = 0;
	while (str[++i])
	{
		if (!check(str[i], charset))
			arr[cnt_char++] = str[i];
		else
		{
			if (cnt_char != 0)
				make_malloc(idx++, arr, ptr, &cnt_char);
		}
	}
	if (cnt_char != 0)
		make_malloc(idx, arr, ptr, &cnt_char);
	return (mshan_allah(ptr));
}
/*int main(void)
{
  char **ret;
  ret = ft_split("hello world here", " h");
  for (int i = 0; i < 3; ++i) {
printf("%s\n",
ret[i]);
  }
}*/
