/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:25:11 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/06 13:16:07 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define FACTOR	32

// open //
# include <fcntl.h>
// malloc // free //
# include <stdlib.h>
// perror
# include <stdio.h>
// strerror
# include <string.h>
// exit // close // read // write //
# include <unistd.h>
// math //
# include <math.h>
// mlx //
# include "mlx/mlx.h"
// libft //
# include "../libft/libft.h"

# include <X11/keysym.h>
# include <stdbool.h>

typedef struct s_env
{
	void	*mlx;
	void	*win;
	char	**map;
	size_t	width;
	size_t	height;
	int		factor;
}	t_env;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_ent
{
	int		x;
	int		y;
	char	*e;
}	t_ent;



#endif