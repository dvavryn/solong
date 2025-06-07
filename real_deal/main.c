#include "solong.h"
#include <string.h>
int main(void)
{
	t_data data;
	t_player dom;
	dom.x = 32;
	dom.y = 32;
	data.player = &dom;
	int		i[2];

	// char *mapin[] = {
	// 	"1111111111111",
	// 	"10010000000C1",
	// 	"1000011111001",
	// 	"1P0011E000001",
	// 	"1111111111111",
	// 	NULL
	// };

	char *mapin[] = {
		"1111111111111111111111111111111111",
		"1E0000000000000C00000C000000000001",
		"1010010100100000101001000000010101",
		"1010010010101010001001000000010101",
		"1P0000000C00C0000000000000000000C1",
		"1111111111111111111111111111111111",
		NULL
	};

	data.map->map = mapin;

	int	win_width = strlen(data.map->map[0]) * 32;
	int	win_height = 6 * 32;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, win_width, win_height, "Mario");

	data.textures[0] = mlx_xpm_file_to_image(data.mlx, "../textures/xpm/star.xpm", &i[0], &i[1]);
	data.textures[1] = mlx_xpm_file_to_image(data.mlx, "../textures/xpm/oiram.xpm", &i[0], &i[1]);
	data.textures[2] = mlx_xpm_file_to_image(data.mlx, "../textures/xpm/pipe.xpm", &i[0], &i[1]);
	data.textures[3] = mlx_xpm_file_to_image(data.mlx, "../textures/xpm/brick.xpm", &i[0], &i[1]);
	data.textures[4] = mlx_xpm_file_to_image(data.mlx, "../textures/xpm/BG.xpm", &i[0], &i[1]);

	size_t	k;
	size_t	j;

	k = 0;
	while (k < win_height / 32)
	{
		j = 0;
		while (j < win_width / 32)
		{
			mlx_put_image_to_window(data.mlx, data.win, data.textures[4], j *32, k * 32);
			if (data.map->map[k][j] == '1')
				mlx_put_image_to_window(data.mlx, data.win, data.textures[3], j * 32, k * 32);
			if (data.map->map[k][j] == 'C')
				mlx_put_image_to_window(data.mlx, data.win, data.textures[0], j * 32, k * 32);
			if (data.map->map[k][j] == 'P')
				mlx_put_image_to_window(data.mlx, data.win, data.textures[1], j * 32, k * 32);
			if (data.map->map[k][j] == 'E')
				mlx_put_image_to_window(data.mlx, data.win, data.textures[2], j * 32, k * 32);
			j++;
		}
		k++;;
	}











	// mlx_put_image_to_window(data.mlx, data.win, data.textures[0], 100 - 16, 100 - 16);
	// mlx_put_image_to_window(data.mlx, data.win, data.textures[1], 200 - 16, 100 - 16);
	// mlx_put_image_to_window(data.mlx, data.win, data.textures[2], 300 - 16, 100 - 16);
	// mlx_put_image_to_window(data.mlx, data.win, data.textures[3], 400 - 16, 100 - 16);
	mlx_key_hook(data.win, hooks, &data);
	mlx_loop(data.mlx);
}
