/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:24:57 by tbabayan          #+#    #+#             */
/*   Updated: 2022/07/31 18:07:03 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

static void	change_direction(t_game *var, char c)
{
	mlx_destroy_image(var->mlx, var->player);
	if (c == 'a')
		var -> player = mlx_xpm_file_to_image(var -> mlx, "images/Player_A.xpm",
				&var -> length_of_img, &var-> height_of_img);
	else if (c == 'd')
		var -> player = mlx_xpm_file_to_image(var -> mlx, "images/Player_D.xpm",
				&var -> length_of_img, &var-> height_of_img);
}

void	play_a(t_game *var)
{
	change_direction(var, 'a');
	if ((var->map[var->y_p][var->x_p] == 'E' && var->num_of_c == 0)
			|| var->map[var->y_p][var->x_p] == 'K')
		exit_esc(var);
	else if (var->map[var->y_p][var->x_p] == '1'
		|| var->map[var->y_p][var->x_p] == 'E')
			var->x_p++;
	else
	{
		if (var->map[var->y_p][var->x_p] == 'C')
			var->num_of_c--;
		var -> move++;
		var->map[var->y_p][var->x_p + 1] = '0';
		var->map[var->y_p][var->x_p] = 'P';
		draw_map(var);
	}
}

void	play_w(t_game *var)
{
	if ((var->map[var->y_p][var->x_p] == 'E' && var->num_of_c == 0)
			|| var->map[var->y_p][var->x_p] == 'K')
		exit_esc(var);
	else if (var->map[var->y_p][var->x_p] == '1'
		|| var->map[var->y_p][var->x_p] == 'E')
			var->y_p++;
	else
	{
		if (var->map[var->y_p][var->x_p] == 'C')
			var->num_of_c--;
		var -> move++;
		var->map[var->y_p + 1][var->x_p] = '0';
		var->map[var->y_p][var->x_p] = 'P';
		draw_map(var);
	}
}

void	play_s(t_game *var)
{
	if ((var->map[var->y_p][var->x_p] == 'E' && var->num_of_c == 0)
		|| var->map[var->y_p][var->x_p] == 'K')
		exit_esc(var);
	else if (var->map[var->y_p][var->x_p] == '1'
		|| var->map[var->y_p][var->x_p] == 'E')
			var->y_p--;
	else
	{
		if (var->map[var->y_p][var->x_p] == 'C')
			var->num_of_c--;
		var -> move++;
		var->map[var->y_p - 1][var->x_p] = '0';
		var->map[var->y_p][var->x_p] = 'P';
		draw_map(var);
	}
}

void	play_d(t_game *var)
{
	change_direction(var, 'd');
	if ((var->map[var->y_p][var->x_p] == 'E' && var->num_of_c == 0)
			|| var->map[var->y_p][var->x_p] == 'K')
		exit_esc(var);
	else if (var->map[var->y_p][var->x_p] == '1'
		|| var->map[var->y_p][var->x_p] == 'E')
			var->x_p--;
	else
	{
		if (var->map[var->y_p][var->x_p] == 'C')
			var->num_of_c--;
		var -> move++;
		var->map[var->y_p][var->x_p - 1] = '0';
		var->map[var->y_p][var->x_p] = 'P';
		draw_map(var);
	}
}
