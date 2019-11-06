/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:53:13 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/16 17:32:06 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_sqrt(int nb)
{
	int sq;

	sq = nb;
	while (sq > 0)
	{
		if (nb % sq == 0 && sq * sq == nb)
			return (sq);
		else
			sq--;
	}
	return (0);
}

int		ft_sqrt(int nb)
{
	int	res;

	res = check_sqrt(nb);
	if (res == 0)
	{
		while (res == 0)
		{
			nb++;
			res = check_sqrt(nb);
		}
	}
	return (res);
}
