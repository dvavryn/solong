#include <mlx.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

#define _WIDTH 800
#define _HEIGHT 800


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	*player;
}	t_env;

void	destroy(t_env *env, int status);
int		hook_esc(int key, t_env *env);
void	fail_destroy(t_env *env);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	draw_line(t_img *img, int x1, int y1, int x2, int y2, int color);
// int		keypress(int key, t_env *env);

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_env env;

	int	i[2];
	env.mlx = mlx_init();
	if (!env.mlx)
		return (1);
	env.win = mlx_new_window(env.mlx, _WIDTH, _HEIGHT, "so-long");
	if (!env.win)
	{
		mlx_destroy_display(env.mlx);
		free(env.mlx);
		return (2);
	}
	// env.player = mlx_xpm_file_to_image(env.mlx, "./textures/oiram.xpm", &i[0], &i[1]);
	

	t_img	img;
	img.img = mlx_new_image(env.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// my_pixel_put(&img, 400, 400, 0x00FF0000);
	draw_line(&img, 100, 100, 150, 100, 0x00FF0000);
	mlx_put_image_to_window(env.mlx, env.win, img.img, 0, 0);


	
	
	
	
	
	// mlx_put_image_to_window(env.mlx, env.win, env.player, _WIDTH / 2, _HEIGHT / 2);

	mlx_key_hook(env.win, hook_esc, &env);
	mlx_loop(env.mlx);
}

// int keypress(int key, t_env *env)
// {
// 	if (key == XK_Escape)
// 		destroy(env, 0);
// 	else if (key == XK_w) //up
// 		printf("up\n");
// 	else if (key == XK_s) //down
// 		printf("down\n");
// 	else if (key == XK_a) //left
// 		printf("left\n");
// 	else if (key == XK_d) //right
// 		printf("right\n");
// 	return (0);
// }

int	hook_esc(int key, t_env *env)
{
	if (key == XK_Escape)
		destroy(env, 0);
	return (0);
}

void	destroy(t_env *env, int status)
{
	mlx_destroy_window(env->mlx, env->win);
	env->win = NULL;
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	env->mlx = NULL;
	exit (0);
}

void	fail_destroy(t_env *env)
{
	if (!env)
		exit(1);
	else if (!env->mlx)
		exit(2);
	else if (!env->win)
	{
		mlx_destroy_display(env->mlx);
		exit(3);
	}
	else if (!env->player)
	{
		mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_display(env->mlx);
		exit(4);
	}
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*px;

	if (x >= 0 && x < _WIDTH && y >= 0 && y < _HEIGHT)
	{
		px = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)px = color;
	}
}

void	draw_line(t_img *img, int x1, int y1, int x2, int y2, int color)
{
	int step;
	int x;
	int y;
	int i;
	int delta_x;
	int delta_y;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	if (abs(delta_x) >= delta_y)
		step = abs(delta_x);
	else
		step = abs(delta_y);
	delta_x = delta_x / step;
	delta_y = delta_y / step;
	x = x1;
	y = x2;
	while (i < step)
	{
		my_pixel_put(img, x, y, color);
		x += delta_x;
		y += delta_y;
		i++;
	}
}