/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:12:48 by tbabayan          #+#    #+#             */
/*   Updated: 2022/07/29 18:02:14 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

static void	put_image_to_window(t_game *var, int j, int i)
{
	if (var -> map[i][j] == '1')
		mlx_put_image_to_window(var->mlx, var->window,
			var->wall, j * 95, i * 95);
	else if (var -> map[i][j] == '0')
		mlx_put_image_to_window(var->mlx, var->window,
			var->background, j * 95, i * 95);
	else if (var -> map[i][j] == 'P')
		mlx_put_image_to_window(var->mlx, var->window,
			var->player, j * 95, i * 95);
	else if (var -> map[i][j] == 'E')
		mlx_put_image_to_window(var->mlx, var->window,
			var->exit, j * 95, i * 95);
	else if (var -> map[i][j] == 'C')
		mlx_put_image_to_window(var->mlx, var->window,
			var->collectible, j * 95, i * 95);
	else if (var -> map[i][j] == 'K')
		mlx_put_image_to_window(var->mlx, var->window,
			var->enemy, j * 95, i * 95);
}

static int	move(int keycode, t_game *var)
{
	if (keycode == 0)
	{
		var->x_p--;
		play_a(var);
	}
	else if (keycode == 13)
	{
		var->y_p--;
		play_w(var);
	}
	else if (keycode == 1)
	{
		var->y_p++;
		play_s(var);
	}
	else if (keycode == 2)
	{
		var->x_p++;
		play_d(var);
	}
	else if (keycode == 53)
		exit_esc(var);
	return (0);
}

int	enemy_animation(t_game *var)
{
	if (var->loop != 1000)
		var->loop++;
	else
	{
		mlx_destroy_image(var->mlx, var->enemy);
		set_animation(var);
		draw_map(var);
		var->enemy_position++;
		var->loop = 0;
	}
	return (0);
}

void	events(t_game *var)
{
	mlx_hook(var->window, 2, 1L << 0, move, var);
	mlx_hook(var->window, 17, 1L << 17, exit_esc, var);
	mlx_loop_hook(var->mlx, enemy_animation, var);
}

void	draw_map(t_game *var)
{
	int	i;
	int	j;

	i = 0;
	while (var -> map[i])
	{
		j = 0;
		while (var -> map[i][j])
		{
			put_image_to_window(var, j, i);
			if (var -> map[i][j] == 'P')
			{
				var->x_p = j;
				var->y_p = i;
			}
			j++;
		}
		i++;
	}
	set_move_text(var);
}
