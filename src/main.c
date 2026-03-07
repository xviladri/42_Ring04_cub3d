/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:49:15 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/07 17:57:24 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/cub3d.h"
#include "../libs/minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h> // para la función exit()

#define ESC_KEY 65307//es la tecla ESC en Linux

//2. SISTEMA DE ERRORES Y LIMPIEZA
void	free_and_exit(t_map *data, char *error_msg)
{
	printf("Error\n%s\n", error_msg);
	if (data)
	{
		//Ayoub: anyadir los free() a medida que reservemos memoria:
		//if (data -> cardinal.no) free(data->caridnal.no);
		//if (data -> map) free_matrix(data->map);
		// etc...
	}
	exit(1);//salir con error
}

//1. INICIALIZAMOS LA ESTRUCTURA: ponemos todo a NULL y 0. Asi cuando hacemos free() de punteros con basura de memoria, el programa no da seg fault
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
	//faltaria inicializar t_player y t_keys (si no cabe aqui, en otra funcion (por la Norminette).
}

//3. VALIDAR ARGUMENTOS
void	check_args(int argc, char **argv, t_map *data)
{
	int	len;
	//Regla 1: solo deben haber 2 aargs (./cub3D y el mapa)
	if (argc != 2)
		free_and_exit(data, "Invalid num. of arguments. Use: ./cub3D <map.cub>");
	//Regla 2: el archivo q le pasamos tiene que terminar en ".cub"
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(&argv[1][len - 4], ".cub", 4) != 0)
		free_and_exit(data, "The file must have the extension .cub");
}

//PUNTO DE ENTRADA
int	main(int argc, char **argv)
{
	t_map	data;
	//1. inicializamos todo a 0 de forma segura
	init_map_data(&data);
	//2. comprobamos argumentos
	check_args(argc, argv, &data);
	//Si llegmos aqui, los argumentos estan perfectos
	printf("FUNCIONA: los argumentos son correctos. File: %s\n", argv[1]);
	//3.AYOUB: hacer la funcion: parse_cub_file(argv[1], &data);
	parse_cub_file(argv[1], &data);
	//4.XENIA: hacer la funcion: init_graphics(&dat);
	return (0);
}
