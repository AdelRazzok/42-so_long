/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:36:25 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/14 17:52:26 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"
#include "../libft/include/libft.h"

char	**get_map(int fd)
{
	char	map[1024];
	char	buf[1];
	int		i;

	i = 0;
	while (read(fd, buf, 1) > 0)
	{
		map[i] = buf[0];
		i++;
	}
	map[i] = '\0';
	return (ft_split(map, '\n'));
}

int	init_data(t_data *data, int fd)
{
	init_map_data(&(data->map_data), fd);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->map_data.width * 32, data->map_data.height * 32, "So long");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 1);
	init_images(data, &(data->images));
	data->nb_moves = 0;
	return (0);
}

void	init_map_data(t_map *map_data, int fd)
{
	map_data->map = get_map(fd);
	map_data->width = 0;
	map_data->height = 0;
	map_data->nb_P = 0;
	map_data->nb_C = 0;
	map_data->nb_E = 0;
	map_data->player_x = 0;
	map_data->player_y = 0;
	get_map_size(map_data);
	count_special_chars(map_data);
	get_p_position(map_data);
}

void	init_images(t_data *data, t_images *images)
{
	images->width = 32;
	images->height = 32;
	images->tree = "./textures/backgrounds/tree.xpm";
	images->grass = "./textures/backgrounds/grass.xpm";
	images->player = "./textures/characters/front.xpm";
	images->antidote = "./textures/items/antidote.xpm";
	images->exit = "./textures/backgrounds/exit.xpm";
	images->img_tree = mlx_xpm_file_to_image(data->mlx_ptr,
			images->tree, &(images->width), &(images->height));
	images->img_grass = mlx_xpm_file_to_image(data->mlx_ptr,
			images->grass, &(images->width), &(images->height));
	images->img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			images->player, &(images->width), &(images->height));
	images->img_antidote = mlx_xpm_file_to_image(data->mlx_ptr,
			images->antidote, &(images->width), &(images->height));
	images->img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			images->exit, &(images->width), &(images->height));
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	if (argc < 2)
		return (write(1, "Error\nAt least one arg required.\n", 33), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(1, "Error\nNo such file or directory.\n", 33), 1);
	data = malloc(sizeof(t_data));
	init_data(data, fd);
	if (!check_map(data->map_data))
		return (write(1, "Error\nInvalid map.\n", 19), 1);
	render_loop(data);
	free(data);
	return (0);
}
