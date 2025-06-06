#include <mlx.h>
#include <stddef.h>
#include "solong.h"

int main(void)
{
	t_env env;

	env.factor = 32;
	env.height = 15 * env.factor;
	env.width = env.height;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.width, env.height, "Mario");

	t_img img;
	img.img = mlx_xpm_file_to_image(env.mlx, "./textures/xpm/bricks", &env.factor, &env.factor);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

	mlx_loop(env.mlx);
}