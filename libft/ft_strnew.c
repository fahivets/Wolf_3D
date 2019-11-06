/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:45:21 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/11/24 22:29:31 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(sizeof(*new) * (size + 1));
	if (new == NULL)
		return (NULL);
	while (i <= size)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
