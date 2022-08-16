/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:09:42 by tbabayan          #+#    #+#             */
/*   Updated: 2022/07/29 18:00:29 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;

	int		num_of_p;
	int		num_of_e;
	int		num_of_c;

	int		height_of_img;
	int		length_of_img;
	int		height_of_map;
	int		length_of_map;

	void	*player;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*background;
	void	*enemy;

	int		loop;
	int		enemy_position;

	int		x_p;
	int		y_p;
	int		move;
}				t_game;

void	check_map(t_game *var);
void	draw_map(t_game *var);
void	events(t_game *var);
void	set_animation(t_game *var);
int		enemy_animation(t_game *var);
void	set_move_text(t_game *var);

void	play_a(t_game *var);
void	play_w(t_game *var);
void	play_s(t_game *var);
void	play_d(t_game *var);

int		exit_esc(t_game *var);
#endif
