# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xviladri <xviladri@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/28 17:01:19 by xviladri          #+#    #+#              #
#    Updated: 2026/02/28 18:11:17 by xviladri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME        = cub3D
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

# Rutas de tus librerías
LIBFT_DIR   = libs/libft
MLX_DIR     = libs/minilibx-linux

# Archivos compilados de las librerías (.a)
LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

# Flags para que Linux y MinilibX se entiendan
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# Archivos fuente
SRC_DIR     = src
OBJ_DIR     = obj
SRC_FILES   = main.c
SRCS        = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# ==== COLORS ======
GREEN   = \033[1;32m
CYAN    = \033[1;36m
YELLOW  = \033[1;33m
PURPLE  = \033[1;35m
PINK    = \033[38;5;206m
FUCSIA = \033[38;5;198m
RESET   = \033[0m

# === ASCII ART ===
define HORSE_ART
$(CYAN)                                 |\\    /|     
$(CYAN)                              ___| \\,,/_/     
$(CYAN)                           ---__/ \\/    \\     
$(CYAN)                          __--/     (D)  \\    
$(CYAN)                          _ -/    (_      \\   
$(CYAN)                         // /       \\_ / ==\\  
$(CYAN)   __-------_____--___--/           / \\_ O o) 
$(CYAN)  /                                 /   \\==/  
$(CYAN) /                                 /          
$(CYAN)||          )                   \\_/\\          
$(CYAN)||         /              _      /  |         
$(CYAN)| |      /--______      ___\\    /\\  :         
$(CYAN)| /   __-  - _/   ------    |  |   \\ \\        
$(CYAN) |   -  -   /                | |     \\ )      
$(CYAN) |  |   -  |                 | )     | |      
$(CYAN)  | |    | |                 | |    | |       
$(CYAN)  | |    < |                 | |   |_/        
$(CYAN)  < |    /__\\                <  \\             
$(CYAN)  /__\\                       /___\\         
$(RESET)
endef
export HORSE_ART

# Includes (donde buscar los .h)
INCLUDES    = -I inc -I $(LIBFT_DIR) -I $(MLX_DIR)

all: $(NAME)

# Compilar libft si no lo está
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compilar minilibx si no lo está
$(MLX):
	@make -C $(MLX_DIR)

# Crear la carpeta obj si no existe y compilar los .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Unir todo en el ejecutable final
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$$HORSE_ART"
	@printf "$(YELLOW)====================================================\n$(RESET)"
	@printf "$(PINK) 🚀 ¡cub3D del equipo 'Stdin or Stdout' está ON!\n$(RESET)"
	@printf "$(FUCSIA) 🕹️  Up to you para que lo pruebes y lo disfrutes.\n$(RESET)"
	@printf "$(YELLOW)====================================================\n$(RESET)"

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
