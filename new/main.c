/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:13:26 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/16 16:48:59 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "../../libft/libft.h"

#ifndef WIN_WIDTH
# define WIN_WIDTH 800
#endif
#ifndef WIN_HEIGHT
# define WIN_HEIGHT 800
#endif

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	char	**map;
}	t_mlx;

int close_(t_mlx **kek)
{
	mlx_loop_end((*kek)->mlx);
	return (0);
}

int	key_handle(int key, t_mlx **kek)
{
	if (key == 65307)
		mlx_loop_end((*kek)->mlx);
	return (0);
}

void	init_kek(t_mlx **kek)
{
	(*kek) = malloc(sizeof(t_mlx));
	if (!(*kek))
		exit(1);
	(*kek)->mlx = mlx_init();
	if (!(*kek)->mlx)
		exit(1);
	(*kek)->win = mlx_new_window((*kek)->mlx, WIN_WIDTH, WIN_HEIGHT, "solong");
	if (!(*kek)->win)
	{
		mlx_destroy_display((*kek)->mlx);
		free((*kek)->mlx);
		free(*kek);
		exit(1);
	}
}

void free_mlx(t_mlx *kek)
{
	mlx_destroy_window(kek->mlx, kek->win);
	mlx_destroy_display(kek->mlx);
	free(kek->mlx);
	free(kek);
	exit(0);
}

int	main(void)
{
	t_mlx	*kek;

	kek = NULL;
	init_kek(&kek);
	mlx_hook(kek->win, 17, 1L <<0, close_, &kek);
	mlx_key_hook(kek->win, key_handle, &kek);
	mlx_loop(kek->mlx);
	free_mlx(kek);
}
