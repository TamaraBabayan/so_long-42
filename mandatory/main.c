/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <tbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:33:41 by tbabayan          #+#    #+#             */
/*   Updated: 2022/08/01 16:20:41 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

static int	check_ber(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	i -= 4;
	if (ft_strcmp(argv + i, ".ber") == 0)
		return (1);
	return (0);
}

static void	read_and_check_map(char *argv, t_game *var)
{
	char	*str;
	char	*line;
	char	*tmp;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(1);
	str = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = str;
		str = ft_strjoin(tmp, line);
		free (tmp);
		free (line);
		line = get_next_line(fd);
	}
	var -> map = ft_split(str, '\n');
	free (str);
	check_map(var);
}

static void	size_of_map(t_game *var)
{
	int	i;

	i = 0;
	var -> move = 0;
	var -> height_of_img = 95;
	var -> length_of_img = 95;
	while (var ->map[i])
		i++;
	var -> height_of_map = i * var -> height_of_img;
	var -> length_of_map = (int)ft_strlen(var -> map[0]) * var -> length_of_img;
}

static void	set_images(t_game *var)
{
	var -> player = mlx_xpm_file_to_image(var -> mlx, "images/Player_D.xpm",
			&var -> length_of_img, &var-> height_of_img);
	var -> wall = mlx_xpm_file_to_image(var -> mlx, "images/Wall.xpm",
			&var -> length_of_img, &var-> height_of_img);
	var->collectible = mlx_xpm_file_to_image(var->mlx, "images/Collectible.xpm",
			&var -> length_of_img, &var-> height_of_img);
	var -> exit = mlx_xpm_file_to_image(var -> mlx, "images/Exit.xpm",
			&var -> length_of_img, &var-> height_of_img);
	var -> background = mlx_xpm_file_to_image(var->mlx, "images/Background.xpm",
			&var -> length_of_img, &var-> height_of_img);
}

int	main(int argc, char **argv)
{
	t_game	var;

	if (argc == 2 && check_ber(argv[1]))
	{
		read_and_check_map(argv[1], &var);
		var.mlx = mlx_init();
		size_of_map(&var);
		var.window = mlx_new_window(var.mlx, var.length_of_map,
				var.height_of_map, "So_long");
		set_images(&var);
		draw_map(&var);
		events(&var);
		mlx_loop(var.mlx);
	}
	else
	{
		write(2, "Invalid Map!!!\n", 15);
		exit (1);
	}
	return (0);
}
