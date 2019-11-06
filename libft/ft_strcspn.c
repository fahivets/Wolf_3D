/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:37:08 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/12/06 21:00:10 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *charset)
{
	const char *string;
	const char *stopset;

	string = (const char *)s;
	while (*string)
	{
		stopset = (const char *)charset;
		while (*stopset)
		{
			if (*string == *(stopset++))
				return (string - s);
		}
		string++;
	}
	return (string - s);
}
