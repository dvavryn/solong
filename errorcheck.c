/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:09:29 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/16 12:47:33 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	check_shape(char **map);
static void	check_symbols(char **map);
static void	check_walls(char **map);
static void	check_occurance(char **map);

void	errorcheck(char **map)
{
	check_shape(map);
	check_symbols(map);
	check_walls(map);
	check_occurance(map);
}

static void	check_occurance(char **map)
{
	size_t	ex;
	size_t	start;
	size_t	collect;
	size_t	i;
	size_t	j;

	ex = count('E', map);
	start = count('P', map);
	collect = count('C', map);
	if (ex == 1 && start == 1 && collect >= 1)
		return ;
	free_split(map);
	write(2, "ERROR\n", 7);
	if (ex != 1)
		write(2, "Amount of exits is not 1\n", 26);
	if (start != 1)
		write(2, "Amount of starts is not 1\n", 27);
	if (collect < 1)
		write(2, "There are no collectibles\n", 27);
	exit(1);
}

static void	check_walls(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (((i == 0 || !map[i + 1]) || (j == 0 || !map[i][j + 1]))
				&& map[i][j] != '1')
			{
				free_split(map);
				write(2, "ERROR\nMap not surrounded by walls!\n", 36);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

static void	check_shape(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
		{
			free_split(map);
			write(2, "ERROR\nDifferent line lengths\n", 30);
			exit(1);
		}
		i++;
	}
}

static void	check_symbols(char **map)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (!(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'))
			{
				free_split(map);
				write(2, "ERROR\nWrong characters inside of map!\n", 39);
				exit (1);
			}
			j++;
		}
		i++;
	}
}
