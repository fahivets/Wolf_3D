/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 20:02:56 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/11/12 18:42:32 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	if (b == NULL)
		return (NULL);
	str = b;
	while (len)
	{
		*str = c;
		str++;
		len--;
	}
	return (b);
}
