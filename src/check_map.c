/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:38:42 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/12 15:11:16 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/include/libft.h"

int	is_rectangle(char **map)
{
	int	nb_col;
	int	i;

	i = 0;
	nb_col = ft_strlen(map[i]);
	while (map[i])
	{
		if (nb_col != (int)ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_closed(t_map map_data)
{
	int	i;
	int	j;

	i = 0;
	while (map_data.map[i])
	{
		j = 0;
		while (map_data.map[i][j])
		{
			if (i == 0 || i == (map_data.height - 1)
				|| j == 0 || j == (map_data.width -1))
			{
				if (map_data.map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_path(t_map map_data, char **map_cpy)
{
	int	i;
	int	j;

	flood_fill(map_data.player_x, map_data.player_y, map_data, map_cpy);
	i = 0;
	while (map_cpy[i])
	{
		j = 0;
		while (map_cpy[i][j])
		{
			if (map_cpy[i][j] == 'C' || map_cpy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_map map_data)
{
	char	*map_cpy[1024];
	int		i;

	if (!is_rectangle(map_data.map))
		return (0);
	if (!is_closed(map_data))
		return (0);
	if (!is_valid_chars(map_data.map))
		return (0);
	if (map_data.nb_P != 1 || map_data.nb_C < 1 || map_data.nb_E != 1)
		return (0);
	i = 0;
	while (map_data.map[i])
	{
		map_cpy[i] = ft_strdup(map_data.map[i]);
		i++;
	}
	if (!is_valid_path(map_data, map_cpy))
		return (0);
	return (1);
}
