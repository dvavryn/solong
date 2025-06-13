/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:13:26 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/13 20:13:42 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include <stdlib.h>

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

int	close(int key, t_mlx *kek)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(kek->mlx, kek->win);
		mlx_destroy_display(kek->mlx);
		free(kek->mlx);
		exit(0);
	}
	return (0);
}

void	init_kek(t_mlx *kek)
{
	kek->mlx = mlx_init();
	if (!kek->mlx)
		exit(1);
	kek->win = mlx_new_window(kek->mlx, WIN_WIDTH, WIN_HEIGHT, "solong");
	if (!kek->win)
	{
		mlx_destroy_display(kek->mlx);
		free(kek->mlx);
		exit(1);
	}
}

int	main(void)
{
	t_mlx	kek;

	init_kek(&kek);
	mlx_key_hook(kek.win, close, &kek);
	mlx_loop(kek.mlx);
}
