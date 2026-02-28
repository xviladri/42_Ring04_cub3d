/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:49:15 by xviladri          #+#    #+#             */
/*   Updated: 2026/02/28 17:05:38 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/cub3d.h" // Aquí deberías tener tu struct y librerías incluidas
#include "../libs/minilibx-linux/mlx.h" // Incluimos la librería gráfica directamente por ahora
#include <stdio.h>

int main(void)
{
    void    *mlx_connection;
    void    *mlx_window;

    // 1. Iniciamos la conexión con la pantalla
    mlx_connection = mlx_init();
    if (!mlx_connection)
    {
        printf("Error\nNo se pudo iniciar MiniLibX\n");
        return (1);
    }
    // 2. Creamos una ventana de 800 píxeles de ancho por 600 de alto
    mlx_window = mlx_new_window(mlx_connection, 800, 600, "Mi primer cub3D");
    if (!mlx_window)
    {
        printf("Error\nNo se pudo crear la ventana\n");
        return (1);
    }
    // 3. Entramos en el bucle infinito para que la ventana no se cierre de golpe
    printf("¡Ventana abierta! Pulsa CTRL+C en la terminal para cerrarla.\n");
    mlx_loop(mlx_connection);
    return (0);
}
