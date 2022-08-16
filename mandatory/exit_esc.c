/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_esc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:45:30 by tbabayan          #+#    #+#             */
/*   Updated: 2022/08/01 16:28:36 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	free_map(t_game *var)
{
	int	i;

	i = 0;
	while (var -> map[i])
		free(var->map[i++]);
	free(var->map);
}

int	exit_esc(t_game *var)
{
	mlx_destroy_image(var->mlx, var->player);
	mlx_destroy_image(var->mlx, var->collectible);
	mlx_destroy_image(var->mlx, var->background);
	mlx_destroy_image(var->mlx, var->exit);
	mlx_destroy_image(var->mlx, var->wall);
	mlx_destroy_window(var->mlx, var->window);
	free_map(var);
	free(var->mlx);
	exit(0);
	return (0);
}
