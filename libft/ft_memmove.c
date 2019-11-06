/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:30:41 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/12/04 20:48:43 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (cdst < csrc)
		ft_memcpy(cdst, csrc, len);
	else
	{
		while (len > 0)
		{
			cdst[len - 1] = csrc[len - 1];
			len--;
		}
	}
	return (cdst);
}
