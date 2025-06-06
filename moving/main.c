#include <mlx.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;

}	t_data;

// typedef struct s_img
// {
// 	void	
// }

int	close_(int keycode, t_data *data);

int main(void)
{
	t_data data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 800, 800, "moving");





	mlx_key_hook(data.mlx_win, close_, &data);
	mlx_loop(data.mlx);
}

int	close_(int keycode, t_data *data)
{
	if (keycode == XK_Escape || keycode == XK_q)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		printf("Closed Properly!\n");
		exit(0);
	}
	return (0);
}