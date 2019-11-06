/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:46:50 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/12/06 21:57:17 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok_r(char *str, const char *delim, char **save_ptr)
{
	char	*str_begin;
	char	*str_end;

	if (str != NULL)
		str_begin = str;
	else
		str_begin = *save_ptr;
	str_begin = str_begin + ft_strspn(str_begin, delim);
	if (*str_begin == '\0')
	{
		*save_ptr = NULL;
		return (NULL);
	}
	str_end = str_begin + ft_strcspn(str_begin, delim);
	if (*str_end != '\0')
	{
		*str_end = '\0';
		str_end++;
	}
	*save_ptr = str_end;
	return (str_begin);
}
