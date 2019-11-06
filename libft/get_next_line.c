/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_M.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:47:04 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/04/15 18:52:26 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_line_and_stock(char **line, char **stock)
{
	char	*ptr;

	ptr = *line;
	*line = ft_strjoin(*line, *stock);
	free(ptr);
	ft_strdel(stock);
	return (*line);
}

static char	*join_line_and_buffer(char **line, char *buffer)
{
	char	*ptr;

	ptr = *line;
	*line = ft_strjoin(*line, buffer);
	free(ptr);
	return (*line);
}

static int	check_what_we_read(char *buffer, char **stock, char **line)
{
	char	*temp;
	char	*ptr;

	if ((temp = ft_strchr(buffer, '\n')) != NULL)
	{
		*temp = '\0';
		ptr = *line;
		*line = ft_strjoin(*line, buffer);
		free(ptr);
		*stock = ft_strdup(temp + 1);
		temp = NULL;
		return (1);
	}
	else
	{
		*line = join_line_and_buffer(line, buffer);
		return (0);
	}
}

static int	check_what_we_have_in_stock(char **stock, char **line)
{
	char	*temp;
	char	*ptr;

	if ((temp = ft_strchr(*stock, '\n')) != NULL)
	{
		*temp = '\0';
		ptr = *line;
		*line = ft_strjoin(*line, *stock);
		free(ptr);
		ptr = *stock;
		*stock = ft_strdup(temp + 1);
		free(ptr);
		temp = NULL;
		return (1);
	}
	else
	{
		*line = join_line_and_stock(line, stock);
		return (0);
	}
}

int			get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	int				read_bytes;
	static char		*stock[0];
	char			*ptr;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || (read(fd, buffer, 0)) < 0)
		return (-1);
	*line = ft_strnew(0);
	ft_bzero(buffer, BUFF_SIZE);
	if (stock[fd] && check_what_we_have_in_stock(&stock[fd], line) == 1)
		return (1);
	while ((read_bytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_bytes] = '\0';
		if (check_what_we_read(buffer, &stock[fd], line) == 1)
			return (1);
	}
	if (*line[0] != '\0')
	{
		ptr = *line;
		*line = ft_strdup(*line);
		free(ptr);
		return (1);
	}
	return (0);
}
