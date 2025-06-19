/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvavryn <dvavryn@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:37:17 by dvavryn           #+#    #+#             */
/*   Updated: 2025/06/19 17:39:27 by dvavryn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define WIN_WID 800;
# define WIN_HEI 800;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*textures[5];
	char	**map;
}	t_data;


#endif