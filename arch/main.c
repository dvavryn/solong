/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:24:40 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/06 15:27:45 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int close_esc(int keycode, t_env *env);
void	ft_put_pixel(t_img	*data, int x, int y, int color, t_env *env);
void	ft_put_pixel_block(t_img *data, int x, int y, int color, t_env *env);
size_t	get_height(char **map, int factor);
size_t	get_width(char **map, int factor);
void	get_ent_pos(t_ent *player, t_env *env, char name);

int main(int argc, char **argv)
{
	char	*map[] = {
		"1111111111111",
		"1P010000000C1",
		"1000011111001",
		"100011E000001",
		"1111111111111",
		NULL
	};
	char	*map1[] = {
		"1111111111111111111111111111111111",
		"1E0000000000000C00000C000000000001",
		"1010010100100000101001000000010101",
		"1010010010101010001001000000010101",
		"1P0000000C00C0000000000000000000C1",
		"1111111111111111111111111111111111",
		NULL
	};

	

	t_env	env;
	env.mlx = mlx_init();
	env.map = map1;
	env.factor = FACTOR;
	env.width = get_width(env.map, env.factor);
	env.height = get_height(env.map, env.factor);
	env.win = mlx_new_window(env.mlx, env.width, env.height, "so-long");

	t_img	img;
	img.img = mlx_new_image(env.mlx, env.width, env.height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	
	// draw_backgroud()

	// ft_put_pixel_block(&img, i, j, 0x00FF0000, &env);

	size_t	i;
	size_t	j;

	i = 0;
	while (env.map[i])
	{
		j = 0;
		while (env.map[i][j])
		{
			if (env.map[i][j] == '1')
				ft_put_pixel_block(&img, j * env.factor, i * env.factor, 0x0000FF00, &env);
			if (env.map[i][j] == '0')
				ft_put_pixel_block(&img, j * env.factor, i * env.factor, 0x00808080, &env);
			j++;
		}
		i++;
	}
	
	t_ent dom;
	
	get_ent_pos(&dom, &env, 'P');

	ft_put_pixel_block(&img, dom.x * env.factor, dom.y * env.factor, 0x00FFFF33, &env);
	printf("%c", dom.e[0]);

	get_ent_pos(&dom, &env, 'E');

	ft_put_pixel_block(&img, dom.x * env.factor, dom.y * env.factor, 0x00FF0000, &env);

	mlx_put_image_to_window(env.mlx, env.win, img.img, 0, 0);
	mlx_key_hook(env.win, close_esc, &env);
	mlx_loop(env.mlx);
}

int close_esc(int keycode, t_env *env)
{
	if (keycode == XK_Escape || keycode == XK_q)
	{
		mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		exit(0);
	}
	return (0);
}

void	ft_put_pixel(t_img	*data, int x, int y, int color, t_env *env)
{
	char *px1;
	
	if (x >= 0 && x < env->width && y >= 0 && y < env->height)
		px1 = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)px1 = color;
}


void	ft_put_pixel_block(t_img *data, int x, int y, int color, t_env *env)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (i < env->factor)
	{
		j = 0;
		while (j < env->factor)
		{
			ft_put_pixel(data, x + i, y + j, color, env);
			j++;
		}
		i++;
	}
}

size_t get_width(char **map, int factor)
{
	return ((ft_strlen(map[0]) * factor));
} 

size_t get_height(char **map, int factor)
{
	size_t	i;
	
	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i * factor);
}

void	get_ent_pos(t_ent *player, t_env *env, char name)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (env->map[i])
	{
		j = 0;
		while (env->map[i][j])
		{
			if (env->map[i][j] == name)
			{
				player->x = j;
				player->y = i;
				player->e = &env->map[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}
