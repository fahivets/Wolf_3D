/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:22:45 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/27 19:37:57 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static void		parsing_map(t_parsing *p)
{
	int		i;
	int		j;

	i = 0;
	while (i < p->count_line)
	{
		j = 0;
		if (p->array[i][0] != '1' || p->array[i][p->len_line - 1] != '1')
			error_msg("Parsing error: Stop crashing my map!");
		while (p->array[i][j])
		{
			if (i == 0 || i == p->count_line - 1)
				if (p->array[i][j] != 49)
					error_msg("Parsing error: Bad map argument");
			if (p->array[i][j] == '0')
				p->zero_count++;
			j++;
		}
		i++;
	}
}

static void		create_map(t_parsing *p, char *file_name)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || (read(fd, line, 0) < 0))
		error_msg("Error: Can't open file");
	i = 0;
	p->array = (char **)ft_memalloc(sizeof(char *) * p->count_line);
	while (get_next_line(fd, &line) == 1)
	{
		if (i == 0)
			p->len_line = ft_strlen(line);
		if (ft_strlen(line) > 501)
			error_msg("WTF are you doing?!");
		if (ft_strlen(line) != p->len_line)
			error_msg("Error: Bad line len");
		p->array[i] = ft_strdup(line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}

static void		read_file(t_parsing *p, char *file_name)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || (read(fd, line, 0) < 0))
		error_msg("Error: Can't open file");
	while (get_next_line(fd, &line) == 1)
	{
		p->count_line++;
		if (p->count_line >= 500)
			error_msg("WTF are you doing?!");
		while (line[++i])
			if (ft_isdigit(line[i]) == 0)
				error_msg("Parsing error: Bad map argument");
		i = -1;
		free(line);
	}
	close(fd);
	free(line);
}

int				init_parsing(t_game *g, char *argv)
{
	t_parsing	*p;
	char		*file_name;
	int			i;

	file_name = argv;
	p = (t_parsing *)ft_memalloc(sizeof(t_parsing));
	read_file(p, file_name);
	if (p->count_line == 0)
		error_msg("Error: Empty line");
	create_map(p, file_name);
	parsing_map(p);
	if (p->zero_count == 0)
		error_msg("Parsing error: no emty space in map");
	g->map = (char **)ft_memalloc(sizeof(char *) * p->count_line);
	i = -1;
	while (++i < p->count_line)
		g->map[i] = ft_strdup(p->array[i]);
	ft_arraydel(p->array);
	ft_memdel((void **)&p);
	return (1);
}
