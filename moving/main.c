#include <mlx.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../libft/libft.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;

}	t_data;

void	close_(t_data *data);
int		move(int keycode, t_data *data);
int		handle_key(int keycode, t_data *data);
int		ismove(int keycode);

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 800, 800, "moving");
	mlx_key_hook(data.mlx_win, handle_key, &data);
	mlx_loop(data.mlx);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_(data);
	if (ismove(keycode))
		move(keycode, data);
	return (0);
}

int	ismove(int keycode)
{
	if (keycode == XK_W || keycode == XK_w
		|| keycode == XK_S || keycode == XK_s
		|| keycode == XK_A || keycode == XK_a
		|| keycode == XK_D || keycode == XK_d
		|| keycode == XK_Up || keycode == XK_Down
		|| keycode == XK_Left || keycode == XK_Right)
		return (1);
	return (0);
}

int	move(int keycode, t_data *data)
{
	if (keycode == XK_W || keycode == XK_w || keycode == XK_Up)
		printf("up\n");
	if (keycode == XK_S || keycode == XK_s || keycode == XK_Down)
		printf("down\n");
	if (keycode == XK_A || keycode == XK_a || keycode == XK_Left)
		printf("left\n");
	if (keycode == XK_D || keycode == XK_d || keycode == XK_Right)
		printf("right\n");
	return (0);
}

void	close_(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	printf("Closed Properly!\n");
	exit(0);
}
