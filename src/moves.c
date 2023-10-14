/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:52:28 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/12 18:51:49 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_pos(t_data *data, t_map *map_data)
{
	if (map_data->map[map_data->player_y][map_data->player_x] == 'C')
	{
		map_data->map[map_data->player_y][map_data->player_x] = '0';
		map_data->nb_C--;
	}
	if (map_data->map[map_data->player_y][map_data->player_x] == 'E'
		&& map_data->nb_C == 0)
		on_destroy(data);
}

void	move_left(t_data *data, t_map *map_data)
{
	if (map_data->player_x - 1 >= 0
		&& map_data->map[map_data->player_y][map_data->player_x - 1] != '1')
	{
		map_data->player_x--;
		data->nb_moves++;
	}
	check_pos(data, map_data);
}

void	move_right(t_data *data, t_map *map_data)
{
	if (map_data->player_x + 1 < map_data->width
		&& map_data->map[map_data->player_y][map_data->player_x + 1] != '1')
	{
		map_data->player_x++;
		data->nb_moves++;
	}
	check_pos(data, map_data);
}

void	move_up(t_data *data, t_map *map_data)
{
	if (map_data->player_y - 1 >= 0
		&& map_data->map[map_data->player_y - 1][map_data->player_x] != '1')
	{
		map_data->player_y--;
		data->nb_moves++;
	}
	check_pos(data, map_data);
}

void	move_down(t_data *data, t_map *map_data)
{
	if (map_data->player_y + 1 < map_data->height
		&& map_data->map[map_data->player_y + 1][map_data->player_x] != '1')
	{
		map_data->player_y++;
		data->nb_moves++;
	}
	check_pos(data, map_data);
}
