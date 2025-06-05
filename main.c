/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:24:40 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/05 23:42:50 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int close_esc(int keycode, t_env *env);

int main(int argc, char **argv)
{
	t_env	env;
	env.mlx = mlx_init();
	if (!env.mlx)
		return (1);
	env.map = get_map(argv);
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "so-long");
	if (!env.win)
	{
		mlx_destroy_display(env.mlx);
		free(env.mlx);
		return (2);
	}

	mlx_key_hook(env.win, close_esc, &env);
	mlx_loop(env.mlx);
}

int close_esc(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		exit(0);
	}
	return (0);
}


