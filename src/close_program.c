/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:39:50 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/09 19:20:57 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//1. MANEJO DE ERRORES Y LIMPIEZA
void	free_and_exit(t_map *data, char *error_msg)
{
	printf("Error: llamamos a la funcion free_and_exit.\n%s\n", error_msg);
	if (data)
	{
		//Ayoub: anyadir los free() a medida que reservemos memoria:
		//if (data -> cardinal.no) free(data->caridnal.no);
		//if (data -> map) free_matrix(data->map);
		// etc...
	}
	exit(1);//salir con error
}
// 2. FUNCION PARA CERRAR LA VENTANA CON ESC O LA CRUZ
// Se llama al hacer clic en la X de la ventana (ON_DESTROY)
// mlx_hook espera que devuelva int
int	close_window(t_map *data)
{
	printf("Cerrando el motor 3D limpiamente...\n");
	if (data->imgs && data->imgs->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->imgs->img_ptr);
	if (data->imgs)
		free(data->imgs);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(0);
	return (0);
}
