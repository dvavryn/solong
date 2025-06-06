#include "solong.h"

int main(void)
{
	t_data data;
	t_player dom;
	dom.x = 32;
	dom.y = 32;
	data.player = &dom;
	int		i[2];

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 200, "Mario");

	data.textures[0] = mlx_xpm_file_to_image(data.mlx, "../textures/xpm/star.xpm", &i[0], &i[1]);
	data.textures[1] = mlx_xpm_file_to_image(data.mlx, "../textures/xpm/oiram.xpm", &i[0], &i[1]);
	data.textures[2] = mlx_xpm_file_to_image(data.mlx, "../textures/xpm/pipe.xpm", &i[0], &i[1]);
	data.textures[3] = mlx_xpm_file_to_image(data.mlx, "../textures/xpm/brick.xpm", &i[0], &i[1]);

	printf("%d, %d", i[0], i[1]);
	mlx_put_image_to_window(data.mlx, data.win, data.textures[0], 100 - 16, 100 - 16);
	mlx_put_image_to_window(data.mlx, data.win, data.textures[1], data.player->x - 16, data.player->y - 16);
	mlx_put_image_to_window(data.mlx, data.win, data.textures[2], 300 - 16, 100 - 16);
	mlx_put_image_to_window(data.mlx, data.win, data.textures[3], 400 - 16, 100 - 16);
	mlx_key_hook(data.win, hooks, &data);
	mlx_loop(data.mlx);
}
