/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:01:05 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/06/26 18:39:43 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	negative;
	size_t			len;

	negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	if (n < 0)
	{
		negative = 1;
		len++;
		n = n * (-1);
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
	}
	if (negative == 1)
		str[0] = '-';
	return (str);
}
