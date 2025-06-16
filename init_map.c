/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:00:09 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/16 12:46:48 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static char	*readin(int fd);

char	**init_map(char *path)
{
	int		fd;
	char	*oneline;
	char	**out;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	oneline = readin(fd);
	if (!oneline)
		return (NULL);
	out = ft_split(oneline, '\n');
	free(oneline);
	if (!out)
		return (NULL);
	errorcheck(out);
	return (out);
}

static char	*readin(int fd)
{
	char	s[10];
	char	*out;
	char	*tmp;
	ssize_t	b;

	out = ft_strdup("");
	if (!out)
		exit(1);
	b = 1;
	ft_bzero(s, 10);
	while (b > 0)
	{
		b = read(fd, s, sizeof(s) - 1);
		if (b < 0)
			return (free(out), NULL);
		tmp = out;
		out = ft_strjoin(out, s);
		free(tmp);
		ft_bzero(s, 10);
	}
	return (out);
}
