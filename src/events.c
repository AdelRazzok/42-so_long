/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:41:16 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/12 18:53:23 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../include/so_long.h"
#include "../libft/include/libft.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		on_destroy(data);
	if (keycode == XK_a || keycode == XK_A)
		move_left(data, &(data->map_data));
	if (keycode == XK_d || keycode == XK_D)
		move_right(data, &(data->map_data));
	if (keycode == XK_w || keycode == XK_W)
		move_up(data, &(data->map_data));
	if (keycode == XK_s || keycode == XK_S)
		move_down(data, &(data->map_data));
	ft_printf("Nb moves: %d\n", data->nb_moves);
	render_map(data);
	return (0);
}
