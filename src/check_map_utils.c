/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:17:23 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/14 17:49:53 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/include/libft.h"

void	count_special_chars(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (map_data->map[i])
	{
		j = 0;
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == 'P')
				map_data->nb_P++;
			if (map_data->map[i][j] == 'C')
				map_data->nb_C++;
			if (map_data->map[i][j] == 'E')
				map_data->nb_E++;
			j++;
		}
		i++;
	}
}

void	get_map_size(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_data->map[i][j])
		j++;
	while (map_data->map[i])
		i++;
	map_data->height = i;
	map_data->width = j;
}

void	get_p_position(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (map_data->map[i])
	{
		j = 0;
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == 'P')
			{
				map_data->player_y = i;
				map_data->player_x = j;
				i = -1;
				break ;
			}
			j++;
		}
		if (i == -1)
			break ;
		i++;
	}
}

void	flood_fill(int x, int y, t_map map_data, char **map_cpy)
{
	if (x < 0 || x >= map_data.width || y < 0 || y >= map_data.height)
		return ;
	if (map_cpy[y][x] == '1' || map_cpy[y][x] == 'V')
		return ;
	if (map_cpy[y][x] == '0' || map_cpy[y][x] == 'C' || map_cpy[y][x] == 'E')
		map_cpy[y][x] = 'V';
	flood_fill(x + 1, y, map_data, map_cpy);
	flood_fill(x - 1, y, map_data, map_cpy);
	flood_fill(x, y + 1, map_data, map_cpy);
	flood_fill(x, y - 1, map_data, map_cpy);
}
