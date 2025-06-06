#include <mlx.h>
#include <X11/keysym.h>

#include <stdlib.h>
#include <stdio.h>

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_player
{
	int	x;
	int y;
}	t_player;


typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*textures[4];
	t_map	*map;
	t_player	*player;
}	t_data;


void	close_all(t_data *data);
int	hooks(int key, t_data *data, t_player *player);
int key_is_move(int key);
void destroy(int key, t_data *data);