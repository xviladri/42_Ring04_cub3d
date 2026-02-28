/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:49:15 by xviladri          #+#    #+#             */
/*   Updated: 2026/02/28 18:51:36 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/cub3d.h"
#include "../libs/minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h> // Obligatorio para usar la función exit()

// Definimos el código numérico de la tecla ESC en Linux
#define ESC_KEY 65307

// 1. Nuestra estructura principal (pronto la moveremos a cub3d.h)
typedef struct s_data {
    void    *mlx;
    void    *win;
} t_data;

// 2. Función que se ejecuta para salir limpiamente
// Libera toda la memoria gráfica y cierra el programa
int close_window(t_data *data)
{
    printf("Cerrando el juego limpiamente...\n");
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx); // IMPORTANTE: Función exclusiva de Linux para liberar el display
    free(data->mlx);                // Liberamos el puntero principal de la minilibx
    exit(0);                        // Salimos del programa con código de éxito
    return (0);
}
// 3. Función que "escucha" el teclado
// Se ejecuta cada vez que presionas CUALQUIER tecla
int key_press(int keycode, t_data *data)
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
    t_data  data; // Declaramos nuestra estructura

    // Iniciamos la conexión y la guardamos en la struct
    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    // Creamos la ventana y la guardamos en la struct
    data.win = mlx_new_window(data.mlx, 800, 600, "Mi primer cub3D");
    if (!data.win)
    {
        mlx_destroy_display(data.mlx);
        free(data.mlx);
        return (1);
    }
    // --- LOS HOOKS ---
    // mlx_hook(ventana, numero_de_evento, mascara, funcion_a_ejecutar, parametro_extra)
    // Evento 17 = DestroyNotify (Hacer clic en la cruz roja)
    mlx_hook(data.win, 17, 0, close_window, &data); 
    // Evento 2 = KeyPress (Pulsar cualquier tecla)
    // Usamos la máscara 1L<<0 que es la estándar en X11 para leer teclados
    mlx_hook(data.win, 2, 1L<<0, key_press, &data);
    // Bucle infinito
    printf("¡Ventana abierta! Pulsa ESC o la cruz roja para cerrarla.\n");
    mlx_loop(data.mlx);
    return (0);
}
