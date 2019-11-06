/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:23:36 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/11/13 12:48:53 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (cdst);
}
