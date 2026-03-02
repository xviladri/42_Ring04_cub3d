## ⚙️ AYOUB: **Back-End**

**Misión:** Asegurar que el programa entienda el mundo. Si los datos están mal, el juego colapsará.

### Roadmap de tareas (Orden de ejecución):

1. **Estructura de Datos (`cub3d.h`):** Antes de escribir una sola línea, define la `struct` principal que contendrá todo (texturas, mapa, colores, info del jugador). **--> Ayoub hay una mini estructura empezada en el main.c, llevala al .h**
2. **Manejo de Errores (`error_handler.c`):** Crea una función que libere memoria y escriba `Error\n` seguido de un mensaje personalizado antes de salir. En 42, no se permiten fugas de memoria (*leaks*).
3. **Lector de Archivo (`parse_cub.c` y `detector.c`):** Usarás `get_next_line` para leer el `.cub`. Debes identificar si la línea empieza por `NO`, `SO`, `WE`, `EA` (texturas), `F`, `C` (colores) o si es el mapa.
4. **Almacenamiento (`save.c`):** Convierte los *strings* de colores en valores enteros y guarda las rutas de las texturas. El mapa debe guardarse como un array de strings (`char **map`).
5. **Validación del Mapa (`check.c`):** Esta es la parte más difícil. Debes implementar un algoritmo (tipo *Flood Fill*) para comprobar que el mapa está totalmente cerrado por muros (`1`). Si el jugador puede "escapar" al infinito, el mapa es inválido.
6. **Punto de Inicio (`check_player.c`):** Localiza al jugador (`N`, `S`, `E`, `W`), guarda su posición inicial y su dirección, y luego sustitúyelo por un `0` en el mapa.

---

## 🎨 XENIA: **Front-End**

**Misión:** Convertir los números de Aybelhaj en una imagen 3D.

### Roadmap de tareas (Orden de ejecución):

1. **Inicialización de MLX (`init.c` e `init_img.c`):** Levantar la ventana de la MiniLibX y cargar los archivos `.xpm` de las texturas a imágenes que la MLX pueda manejar.
2. **El Bucle Principal (`main.c`):** Configurar el `mlx_loop_hook`. En 42, el juego debe redibujarse constantemente para que sea fluido.
3. **Lógica del Raycasting (`raycast.c`):** Aquí aplicas el algoritmo **DDA** (Digital Differential Analyzer). Por cada columna de la pantalla (x), lanzas un rayo.

4. **Cálculo de Proyección (`calculate.c`):** Una vez que el rayo choca con un muro, calculas la distancia perpendicular (para evitar el efecto "ojo de pez") y la altura que debe tener esa línea en la pantalla.
5. **Renderizado (`draw_map.c` y `draw_wall.c`):**
   * Pintar el techo y el suelo (colores planos).
   * Pintar la línea vertical del muro usando la textura correspondiente (si el rayo golpeó por el Norte, Sur, Este u Oeste).
6. **Entrada de Usuario (`keys.c` y `keys_handler.c`):** Gestionar `W`, `A`, `S`, `D` para moverte y las flechas para rotar la cámara. **Tip:** Usa vectores para que el movimiento sea fluido.

---

## 🤝 El Punto de Encuentro (La Estructura `t_data`)

Para que ambos podáis trabajar en paralelo, debéis compartir una estructura común en `cub3d.h`. Pensadlo como el contrato de vuestra colaboración:

```c
typedef struct s_data {
    char    **map;          // Aybelhaj lo llena, Xviladri lo lee
    void    *mlx_ptr;       // Xviladri lo inicia
    t_player player;        // Aybelhaj pone el inicio, Xviladri lo mueve
    t_img    tex_north;     // Aybelhaj da la ruta, Xviladri carga el xpm
    // ... rest of variables
} t_data;
```
Importante: entender que el mapa es solo una rejilla 2D, pero el Raycasting nos dice a qué distancia está el objeto frente a nosotros. Si algo está lejos, dibujamos una línea pequeña; si está cerca, una línea grande. ==> efecto visual 3D.

---
---

**AQUI EMPIEZA EL README:**

# 🎮 42_Ring04_cub3d

*This project has been created as part of the 42 curriculum by aybelhaj and xviladri.*

## 🏰 cub3D - My first RayCaster with miniLibX

### 📖 Description

This project is inspired by the world-famous Wolfenstein 3D game, which is considered the first FPS (First Person Shooter) ever created. The main goal of cub3D is to create a dynamic, 3D graphical representation of the inside of a maze from a first-person perspective using ray-casting principles.

Through this project, we explore fundamental graphics programming, window management, event handling (keyboard/mouse), and mathematics as a practical tool to create elegant and efficient rendering algorithms.

### 🗂️ Project Structure

Our project is heavily modularized to maintain clean code and facilitate parallel work:

```text
cub3d/
├── Makefile
├── inc/
│   └── cub3d.h
├── src/
│   ├── main.c           → Punto de entrada, validar argumentos
│   ├── parse_cub.c      → Leer y parsear el archivo .cub
│   ├── detector.c       → Detectar tipo de línea (textura, color, mapa)
│   ├── save.c           → Guardar texturas, colores y mapa
│   ├── check.c          → Validar mapa (cerrado por paredes)
│   ├── check_player.c   → Dirección inicial del jugador
│   ├── error_handler.c  → Manejo de errores
│   ├── init.c           → Inicializar mlx, ventana, jugador
│   ├── init_img.c       → Cargar texturas XPM
│   ├── raycast.c        → Algoritmo de raycasting + DDA
│   ├── calculate.c      → Cálculos de distancias y alturas
│   ├── draw_map.c       → Dibujar techo, pared, suelo
│   ├── draw_wall.c      → Obtener coordenadas de textura
│   ├── keys.c           → Movimiento (W/A/S/D)
│   ├── keys_handler.c   → Gestión de teclas y rotación
│   └── utils.c          → Funciones auxiliares (pixel_put, free, realloc)
├── libs/
│   ├── libft/           → Tu propia libft
│   └── minilibx/        → MiniLibX
├── imgs/                → Texturas .xpm
└── maps/                → Archivos .cub de prueba
```

### 🤝 Task Division

To ensure smooth collaboration, we divided the engine into two main logical blocks:

**1. ⚙️ The Back-End (Data Parsing & Validation)**
  **Focus:** Reading the .cub scene description file safely, storing data, and validating the map.
  * Handling argc and argv.
  * Parsing textures (NO, SO, WE, EA) and floor/ceiling RGB colors.
  * Validating that the map contains only valid characters (0, 1, N, S, E, W) and is strictly closed/surrounded by walls.
  * Memory management and proper error handling.

**2. 🎨 The Front-End (Graphics & Raycasting Engine)**
  **Focus:** Translating the parsed 2D grid into a 3D perspective using the MiniLibX library.
  * **Raycasting:** Shooting invisible rays from the player's view plane for every vertical column of pixels on the screen.
  * **DDA Algorithm:** A fast 2D grid traversal algorithm to detect exactly where the rays hit a wall (1).
  * **Distance & Trigonometry:** Calculating the perpendicular distance to the wall to avoid the "fisheye" effect, and determining the exact height of the wall slice to draw.
  * **Rendering:** Mapping the correct .xpm texture to the wall depending on the compass direction (North, South, East, West) and drawing the floor/ceiling colors.
  * **Movement:** Updating the player's coordinates using W, A, S, D and rotating the camera plane using the Left and Right arrow keys.

### 🚀 Instructions

  **🛠️ Compilation:**
  A Makefile is provided to compile the source files into the required executable. It uses cc with the mandatory flags -Wall -Wextra -Werror.
  * Compile the mandatory part: `make`
  * Clean object files: `make clean`
  * Clean object files and the executable: `make fclean`
  * Recompile everything: `make re`

  **▶️ Execution:**
  Run the compiled program by passing a valid .cub map file as the first argument: 
  ```./cub3D maps/valid_map.cub```

### 📚 Resources

  * **Lodev's Raycasting Tutorial:** The absolute gold standard for understanding Raycasting and the DDA algorithm in C/C++.
  * **Medium Article:** 3D Ray-Casting Game with cub3D - Great overview of the math and structure.
  * **AI Usage Disclaimer:** As per the 42 curriculum guidelines, Artificial Intelligence was used critically as a tutoring tool to understand complex mathematical concepts (like trigonometric calculations for raycasting) and to help structure the code logic. No AI-generated code was blindly copy-pasted; all code was thoroughly reviewed, understood, and typed by the authors.
