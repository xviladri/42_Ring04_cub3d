/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:49:15 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 18:23:21 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/cub3d.h"

// Inicializa la struct entera a 0/NULL para evitar seg faults al hacer free()
void	init_map_data(t_map *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map = NULL;
	data->imgs = NULL;
	data->cardinal.no = NULL;
	data->cardinal.so = NULL;
	data->cardinal.we = NULL;
	data->cardinal.ea = NULL;
	data->floor_exist = 0;
	data->ceiling_exist = 0;
	data->floor_color = 0;
	data->ceiling_color = 0;
	data->map_width = 0;
	data->map_height = 0;
	data->map_started = 0;
	data->player.dir = 0;
	data->keys.w = 0;
	data->keys.s = 0;
	data->keys.a = 0;
	data->keys.d = 0;
	data->keys.rotateleft = 0;
	data->keys.rotateright = 0;
}

// Valida que se pase exactamente 1 argumento con extension .cub
void	check_args(int argc, char **argv, t_map *data)
{
	int	len;

	if (argc != 2)
		free_and_exit(data, "Invalid num. of arguments. Use: ./cub3D <map.cub>");
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(&argv[1][len - 4], ".cub", 4) != 0)
		free_and_exit(data, "The file must have the extension .cub");
}

// PUNTO DE ENTRADA
int	main(int argc, char **argv)
{
	t_map	data;

	init_map_data(&data);
	check_args(argc, argv, &data);
	parse_cub_file(argv[1], &data);
	pad_map(&data);
	check_map_elements(&data);
	check_map_closed(&data);
	init_graphics(&data);
	return (0);
}