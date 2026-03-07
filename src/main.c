/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:49:15 by xviladri          #+#    #+#             */
/*   Updated: 2026/03/07 12:28:54 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/cub3d.h"
#include "../libs/minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h> // para la función exit()
//AYOUB GUAPO
#define ESC_KEY 65307//es la tecla ESC en Linux

// 2. Función que se ejecuta para salir limpiamente
// Libera toda la memoria gráfica y cierra el programa
int close_window(t_map *data)
{
	printf("Cerrando el juego limpiamente...\n");
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);// IMPORTANTE: Función SOLO de Linux para liberar el display
	free(data->mlx_ptr);// Liberamos el puntero principal de la minilibx
	exit(0);
	return (0);
}
// 3. Función que "escucha" el teclado. Se ejecuta cada vez que presionamos CUALQUIER tecla
int key_press(int keycode, t_map *data)
{
	if (keycode == ESC_KEY)
	{
		printf("Has pulsado ESC.\n");
		close_window(data);
    }
	return (0);
}

int main(void)
{
	t_map  data;//Declaramos la estructura
    
	// Iniciamos la conexión y la guardamos en la struct
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);
    // Creamos la ventana y la guardamos en la struct
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Nuestro primer cub3D");
    if (!data.win_ptr)
    {
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
    }
    // --- LOS HOOKS: ---
    // mlx_hook(ventana, numero_de_evento, mascara, funcion_a_ejecutar, parametro_extra)
    // Evento 17 = DestroyNotify ==> sirve para poder cerrar ventana con la cruz
	mlx_hook(data.win_ptr, 17, 0, close_window, &data); 
    // Evento 2 = KeyPress (Pulsar cualquier tecla)
    // Usamos la máscara 1L<<0 que es la estándar en X11 para leer teclados
	mlx_hook(data.win_ptr, 2, 1L<<0, key_press, &data);
    // Bucle infinito
	printf("¡Ventana abierta! Pulsa ESC o la cruz para cerrarla.\n");
	mlx_loop(data.mlx_ptr);
	return (0);
}
