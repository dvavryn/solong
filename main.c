/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:13:26 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/16 12:47:54 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	escape(int key, t_mlx *kek)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(kek->mlx, kek->win);
		mlx_destroy_display(kek->mlx);
		free(kek->mlx);
		free_split(kek->map);
		exit(0);
	}
	return (0);
}

int	keyhandler(int key, t_mlx *kek)
{
	int	ret;

	ret = escape(key, kek);
	return (ret);
}

void	init_kek(t_mlx *kek, char *map_path)
{
	kek->map = init_map(map_path);
	if (!kek->map)
		exit(1);
	kek->mlx = mlx_init();
	if (!kek->mlx)
	{
		free(kek->map);
		exit(1);
	}
	kek->win = mlx_new_window(kek->mlx, WIN_WIDTH, WIN_HEIGHT, "solong");
	if (!kek->win)
	{
		mlx_destroy_display(kek->mlx);
		free(kek->mlx);
		free_split(kek->map);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_mlx	kek;

	if (argc != 2)
		return (1);
	init_kek(&kek, argv[1]);
	mlx_key_hook(kek.win, keyhandler, &kek);
	mlx_loop(kek.mlx);
}
