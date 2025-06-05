/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:24:40 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/05 17:28:45 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init(t_data *solong);

int	main(int argc, char **argv)
{
	t_data	solong;

	init(&solong);
	mlx_loop(solong.mlx);
}

void	init(t_data *solong)
{
	solong->mlx = mlx_init();
	if (!solong->mlx)
		exit(1);
	solong->window = mlx_new_window(solong->mlx, WIN_WIDTH,
			WIN_HEIGHT, "so-long");
	if (!solong->window)
		exit(2);
}
