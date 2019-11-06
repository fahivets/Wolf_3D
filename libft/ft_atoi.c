/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:43:39 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/12/05 18:06:42 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					znak;
	unsigned long int	result;
	int					x;

	x = 0;
	result = 0;
	znak = 1;
	while (ft_iswspace(str[x]) != 0)
		x++;
	if (str[x] == 45)
		znak = -1;
	if (str[x] == 45 || str[x] == 43)
		x++;
	while (str[x] >= 48 && str[x] <= 57)
	{
		result = result * 10 + str[x] - 48;
		if (result >= 9223372036854775807 && znak == 1)
			return (-1);
		else if (result > 9223372036854775807 && znak == -1)
			return (0);
		x++;
	}
	return (result * znak);
}
