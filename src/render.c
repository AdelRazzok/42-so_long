/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:49:53 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/14 17:53:38 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"

void	render_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map_data.map[y])
	{
		x = 0;
		while (data->map_data.map[y][x])
		{
			put_image(data, data->images.img_grass, x, y);
			if (data->map_data.map[y][x] == '1')
				put_image(data, data->images.img_tree, x, y);
			if (data->map_data.map[y][x] == 'C')
				put_image(data, data->images.img_antidote, x, y);
			if (data->map_data.map[y][x] == 'E')
				put_image(data, data->images.img_exit, x, y);
			x++;
		}
		y++;
	}
	put_image(data, data->images.img_player,
		data->map_data.player_x, data->map_data.player_y);
}

int	render_loop(t_data *data)
{
	render_map(data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		on_destroy, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

void	put_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x * 32, y * 32);
}
