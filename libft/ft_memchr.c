/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:43:53 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/11/13 15:17:36 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	d;
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	d = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == d)
			return (str + i);
		i++;
	}
	return (NULL);
}
