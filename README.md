# 42_Ring04_cub3d

*This project has been created as part of the 42 curriculum by aybelhaj and xviladri.*

## cub3D - My first RayCaster with miniLibX

### Description

This project is inspired by the world-famous Wolfenstein 3D game, which is considered the first FPS (First Person Shooter) ever created. The main goal of cub3D is to create a dynamic, 3D graphical representation of the inside of a maze from a first-person perspective using ray-casting principles.

Through this project, we explore fundamental graphics programming, window management, event handling (keyboard/mouse), and mathematics as a practical tool to create elegant and efficient rendering algorithms.

### Project Structure

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

### Task Division

To ensure smooth collaboration, we divided the engine into two main logical blocks:

**1. The Back-End (Data Parsing & Validation)**
**Focus:** Reading the .cub scene description file safely, storing data, and validating the map.
* Handling argc and argv.
* Parsing textures (NO, SO, WE, EA) and floor/ceiling RGB colors.
* Validating that the map contains only valid characters (0, 1, N, S, E, W) and is strictly closed/surrounded by walls.
* Memory management and proper error handling.

**2. The Front-End (Graphics & Raycasting Engine)**
**Focus:** Translating the parsed 2D grid into a 3D perspective using the MiniLibX library.
* **Raycasting:** Shooting invisible rays from the player's view plane for every vertical column of pixels on the screen.
* **DDA Algorithm:** A fast 2D grid traversal algorithm to detect exactly where the rays hit a wall (1).
* **Distance & Trigonometry:** Calculating the perpendicular distance to the wall to avoid the "fisheye" effect, and determining the exact height of the wall slice to draw.
* **Rendering:** Mapping the correct .xpm texture to the wall depending on the compass direction (North, South, East, West) and drawing the floor/ceiling colors.
* **Movement:** Updating the player's coordinates using W, A, S, D and rotating the camera plane using the Left and Right arrow keys.

### Instructions

**Compilation:**
A Makefile is provided to compile the source files into the required executable. It uses cc with the mandatory flags -Wall -Wextra -Werror.
* Compile the mandatory part: `make`
* Clean object files: `make clean`
* Clean object files and the executable: `make fclean`
* Recompile everything: `make re`

**Execution:**
Run the compiled program by passing a valid .cub map file as the first argument: 
`./cub3D maps/valid_map.cub`

### Resources

* **Lodev's Raycasting Tutorial:** The absolute gold standard for understanding Raycasting and the DDA algorithm in C/C++.
* **Medium Article:** 3D Ray-Casting Game with cub3D - Great overview of the math and structure.
* **AI Usage Disclaimer:** As per the 42 curriculum guidelines, Artificial Intelligence was used critically as a tutoring tool to understand complex mathematical concepts (like trigonometric calculations for raycasting) and to help structure the code logic. No AI-generated code was blindly copy-pasted; all code was thoroughly reviewed, understood, and typed by the authors.
