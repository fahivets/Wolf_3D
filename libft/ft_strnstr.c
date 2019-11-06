/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:49:43 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/12/05 18:43:18 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*find;
	size_t	i;
	size_t	j;

	str = (char *)haystack;
	find = (char *)needle;
	i = 0;
	if (len == 0)
		return (NULL);
	if (find[0] == '\0')
		return (&str[i]);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == find[j] && (i + j) < len)
		{
			if (find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
