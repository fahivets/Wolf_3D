/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:31:58 by dsamarsk          #+#    #+#             */
/*   Updated: 2018/12/04 23:37:42 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*shaved;
	size_t		begin;
	size_t		end;

	if (s)
	{
		shaved = (char *)s;
		begin = 0;
		end = 0;
		while (shaved[begin] != '\0' && ft_iswspace(shaved[begin]) != 0)
			begin++;
		if (begin == ft_strlen(shaved))
			return (shaved = ft_strdup(""));
		end = ft_strlen(shaved) - 1;
		while (end > 0 && ft_iswspace(shaved[end]) != 0)
			end--;
		if ((begin == 0) && end == ft_strlen(shaved) - 1)
			return (ft_strdup(shaved));
		return (ft_strsub(shaved, begin, end - begin + 1));
	}
	return (NULL);
}
