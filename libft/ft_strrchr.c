/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:22:42 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/11/14 20:31:33 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = (ft_strlen(str)) + 1;
	while (i--)
	{
		if (str[i] == c)
			return (&str[i]);
	}
	return (NULL);
}
