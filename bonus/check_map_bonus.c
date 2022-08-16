/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:34:05 by tbabayan          #+#    #+#             */
/*   Updated: 2022/07/29 16:37:43 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

static int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		++i;
	j = -1;
	while (map[0][++j] && map[i -1][j])
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
	i = -1;
	while (map[++i])
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (0);
	return (1);
}

static int	check_num(t_game *var)
{
	int	i;
	int	j;

	i = 0;
	var -> num_of_c = 0;
	var -> num_of_e = 0;
	var -> num_of_p = 0;
	while (var -> map[i])
	{
		j = 0;
		while (var -> map[i][j])
		{
			if (var -> map[i][j] == 'C')
				var -> num_of_c++;
			else if (var -> map[i][j] == 'E')
				var -> num_of_e++;
			else if (var -> map[i][j] == 'P')
				var -> num_of_p++;
			j++;
		}
		i++;
	}
	if (var -> num_of_c > 0 && var -> num_of_e > 0 && var -> num_of_p == 1)
		return (1);
	return (0);
}

static int	check_rectangular(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

static int	check_alpha(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("10EPCK", map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(t_game *var)
{
	if (check_alpha(var -> map) && check_num(var)
		&& check_rectangular(var -> map) && check_walls(var -> map))
		return ;
	else
	{
		write(2, "Invalid Map!!!\n", 15);
		exit (1);
	}
}
