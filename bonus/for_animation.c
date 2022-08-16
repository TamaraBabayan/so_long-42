/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:26:58 by tbabayan          #+#    #+#             */
/*   Updated: 2022/07/29 18:04:10 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	set_animation(t_game *var)
{
	if (var->enemy_position == 1)
		var -> enemy = mlx_xpm_file_to_image(var->mlx, "images/Enemy_1.xpm",
				&var -> length_of_img, &var-> height_of_img);
	else if (var->enemy_position == 2)
		var -> enemy = mlx_xpm_file_to_image(var->mlx, "images/Enemy_2.xpm",
				&var -> length_of_img, &var-> height_of_img);
	else if (var->enemy_position == 3)
		var -> enemy = mlx_xpm_file_to_image(var->mlx, "images/Enemy_3.xpm",
				&var -> length_of_img, &var-> height_of_img);
	else if (var->enemy_position == 4)
		var -> enemy = mlx_xpm_file_to_image(var->mlx, "images/Enemy_4.xpm",
				&var -> length_of_img, &var-> height_of_img);
	else if (var->enemy_position == 5)
		var -> enemy = mlx_xpm_file_to_image(var->mlx, "images/Enemy_5.xpm",
				&var -> length_of_img, &var-> height_of_img);
	else if (var->enemy_position == 6)
		var -> enemy = mlx_xpm_file_to_image(var->mlx, "images/Enemy_6.xpm",
				&var -> length_of_img, &var-> height_of_img);
	else if (var->enemy_position == 7)
	{
		var -> enemy = mlx_xpm_file_to_image(var->mlx, "images/Enemy_7.xpm",
				&var -> length_of_img, &var-> height_of_img);
		var->enemy_position = 0;
	}
}

void	set_move_text(t_game *var)
{
	mlx_string_put(var->mlx, var->window, 9, 42, 0x0A0AFF, "Move  ");
	mlx_string_put(var->mlx, var->window, 80, 42, 0x0A0AFF,
		ft_itoa(var->move));
}
