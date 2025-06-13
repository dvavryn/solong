/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:01:04 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/13 21:23:32 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# ifndef WIN_WIDTH
#  define WIN_WIDTH 800
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 800
# endif

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	char	**map;
}	t_mlx;

char	**init_map(char *path);
void	errorcheck(char **map);

#endif