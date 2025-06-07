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
// int		keypress(int key, t_env *env);

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_env env;

	int	i[2];
	env.mlx = mlx_init();
	fail_destroy(&env);
	env.win = mlx_new_window(env.mlx, _WIDTH, _HEIGHT, "so-long");
	fail_destroy(&env);
	env.player = mlx_xpm_file_to_image(env.mlx, "./textures/oiram.xpm", &i[0], &i[1]);
	fail_destroy(&env);
	



	mlx_put_image_to_window(env.mlx, env.win, env.player, _WIDTH / 2, _HEIGHT / 2);
	// ends the program if ESC key is released
	mlx_key_hook(env.win, hook_esc, &env);

	// let the program run with mlx_loop
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
