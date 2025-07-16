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
	int		size;
	int		i;
	char	*ptr;

	size = 0;
	i = 0;
	while (src[i] != '\0')
	{
		size += 1;
		i += 1;
	}
	ptr = (char *)malloc(sizeof(char) * size);
	i = 0;
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i += 1;
	}
	ptr[i] = '\0';
	return (ptr);
}
