/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:59:32 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/12/06 21:00:08 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *charset)
{
	size_t	count;
	size_t	delim;

	count = 0;
	while (*(s + count))
	{
		delim = 0;
		while (*(charset + delim))
		{
			if (*(s + count) == *(charset + delim))
				break ;
			delim++;
		}
		if (*(charset + delim) == '\0')
			return (count);
		count++;
	}
	return (count);
}
