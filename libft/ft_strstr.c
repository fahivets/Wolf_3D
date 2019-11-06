/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:31:56 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/11/14 20:55:50 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*str;
	char	*find;

	str = (char *)haystack;
	find = (char *)needle;
	i = 0;
	if (find[0] == '\0')
		return (&str[i]);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == find[j])
		{
			if (find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
