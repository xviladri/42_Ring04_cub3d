/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:39:50 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/08 14:43:47 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

//MANEJO DE ERRORES Y LIMPIEZA
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
