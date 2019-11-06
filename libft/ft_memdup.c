/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:06:01 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/12/03 19:09:48 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	void	*dest;

	dest = ft_memalloc(n);
	if (dest == NULL)
		return (NULL);
	return (ft_memcpy(dest, src, n));
}
