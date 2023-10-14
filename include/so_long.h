/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arazzok <arazzok@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:36:20 by arazzok           #+#    #+#             */
/*   Updated: 2023/10/14 17:54:53 by arazzok          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct	s_map
{
	char	**map;
	int		width;
	int		height;
	int		nb_P;
	int		nb_C;
	int		nb_E;
	int		player_x;
	int		player_y;
}			t_map;

typedef struct	s_images
{
	int		width;
	int		height;
	char	*tree;
	char	*grass;
	char	*player;
	char	*antidote;
	char	*exit;
	void	*img_tree;
	void	*img_grass;
	void	*img_player;
	void	*img_antidote;
	void	*img_exit;
}			t_images;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map_data;
	t_images	images;
	int			nb_moves;
}			t_data;

//		so_long.c
char 	**get_map(int fd);
int		init_data(t_data *data, int fd);
void	init_map_data(t_map *map_data, int fd);
void	init_images(t_data *data, t_images *images);
//		check_map.c
int		is_rectangle(char **map);
int		is_closed(t_map map_data);
int		is_valid_chars(char **map);
int		is_valid_path(t_map map_data, char **map_copy);
int		check_map(t_map map_data);
//		check_map_utils.c
void	count_special_chars(t_map *map_data);
void	get_map_size(t_map *map_data);
void	get_p_position(t_map *map_data);
void	flood_fill(int x, int y, t_map map_data, char **map_cpy);
//		render.c
void	render_map(t_data *data);
int		render_loop(t_data *data);
void	put_image(t_data *data, void *img, int x, int y);
//		events.c
int		on_destroy(t_data *data);
int		on_keypress(int keycode, t_data *data);
//		moves.c
void	check_pos(t_data *data, t_map *map_data);
void	move_left(t_data *data, t_map *map_data);
void	move_right(t_data *data, t_map *map_data);
void	move_up(t_data *data, t_map *map_data);
void	move_down(t_data *data, t_map *map_data);

#endif