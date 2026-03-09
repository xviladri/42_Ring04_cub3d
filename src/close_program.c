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

#include "../inc/cub3d.h"

// Se llama al hacer clic en la X de la ventana (ON_DESTROY)
// mlx_hook espera que devuelva int
int	close_window(t_map *data)
{
	free_and_exit(data, "Window closed by user");
	return (0); // nunca llega aquí (free_and_exit llama a exit())
}

// MANEJO DE ERRORES Y LIMPIEZA
void	free_and_exit(t_map *data, char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	if (data)
	{
		if (data->cardinal.no)
			free(data->cardinal.no);
		if (data->cardinal.so)
			free(data->cardinal.so);
		if (data->cardinal.we)
			free(data->cardinal.we);
		if (data->cardinal.ea)
			free(data->cardinal.ea);
		// TODO: free(data->map) cuando tengas free_matrix
		// TODO: free(data->imgs) cuando estén las imágenes
	}
	exit(1);
}
