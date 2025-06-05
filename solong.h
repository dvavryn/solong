/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:25:11 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/05 23:41:12 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define WIN_WIDTH	600
# define WIN_HEIGHT 400

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

typedef struct s_env
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
}	t_env;

#endif