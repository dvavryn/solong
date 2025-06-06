#include "solong.h"

int key_is_move(int key)
{
	if (key == XK_W || key == XK_w
		|| key == XK_S || key == XK_s
		|| key == XK_A || key == XK_a
		|| key == XK_D || key == XK_d
		|| key == XK_Up || key == XK_Down
		|| key == XK_Left || key == XK_Right)
		return (1);
	return (0);
}

int	hooks(int key, t_data *data, t_player *player)
{
	if (key == XK_Escape)
	{
		close_all(data);
	}
	// else if (key_is_move(key))
	// {
	else if (key == XK_w)
		player->x -= 32;
	else if (key == XK_s)
		player->x += 32;
	else if (key == XK_a)
		player->y -= 32;
	else if (key == XK_d)
		player->y += 32;
	// }
	else if (key == XK_1)
		mlx_destroy_image(data->mlx, data->textures[0]);
	else if (key == XK_2)
		mlx_destroy_image(data->mlx, data->textures[1]);
	else if (key == XK_3)
		mlx_destroy_image(data->mlx, data->textures[2]);
	else if (key == XK_4)
		mlx_destroy_image(data->mlx, data->textures[3]);
	return (0);
}

void	close_all(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}