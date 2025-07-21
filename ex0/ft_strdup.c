/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad.al-quraan <ahmad.al-quraan@learner.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:07:35 by ahmad.al-qura     #+#    #+#             */
/*   Updated: 2025/07/16 18:07:36 by ahmad.al-qura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*ptr;

	if (!src)
	{
		return (NULL);
	}
	i = 0;
	while (src[i] != '\0')
		i += 1;
	if (i == 0)
	{
		ptr = malloc(sizeof(char) * 1);
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i += 1;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*int main() {
  char *str = ft_strdup("");

  printf("%s", str);
}*/
