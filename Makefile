# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dancel <dancel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 13:49:20 by dancel            #+#    #+#              #
#    Updated: 2024/12/23 22:45:55 by dancel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Variables de Compilation
# ============================
SO_LONG          = so_long
SO_LONG_BONUS    = so_long_bonus
CC               = cc
CFLAGS           = -Wall -Werror -Wextra -g3

# Fichiers et bibliothèques
# ============================
PRINTF     = lib/ft_printf/libftprintf.a
LIBFT      = lib/libft/libft.a
LIBMLX     = lib/minilibx-linux/libmlx_Linux.a
LIBS       = $(LIBMLX) -lmlx -lXext -lX11
INCLUDES   = -Iinclude -Ilib/ft_printf -Ilib/libft -Ilib/minilibx-linux/

# Fichiers source
# ============================
SRC_FILES   = src/so_long.c src/open_and_parse.c src/create_gui.c src/moves.c
OBJ_FILES   = $(SRC_FILES:.c=.o)

SRC_BONUS_FILES   = src_bonus/so_long_bonus.c src_bonus/open_and_parse_bonus.c src_bonus/create_gui_bonus.c src_bonus/map_display.c src_bonus/moves_bonus.c src_bonus/exit_so_long_bonus.c
OBJ_BONUS_FILES   = $(SRC_BONUS_FILES:.c=.o)

# Cible principale
# ============================
all: $(SO_LONG)

$(SO_LONG): $(OBJ_FILES) $(PRINTF) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(INCLUDES) $^ $(LIBS) -o $@

src/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(SO_LONG_BONUS)

$(SO_LONG_BONUS): $(OBJ_BONUS_FILES) $(PRINTF) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(INCLUDES) $^ $(LIBS) -o $@

src_bonus/%.o: src_bonus/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@	

# Compilation des bibliothèques
# ============================

$(LIBMLX):
	@make -s -C lib/minilibx-linux/

$(PRINTF):
	@make -s -C lib/ft_printf

$(LIBFT):
	@make -s -C lib/libft

# Nettoyage des fichiers
# ============================
clean:
	@make clean -s -C lib/ft_printf
	@make clean -s -C lib/libft
	@make clean -s -C lib/minilibx-linux/
	@rm -f $(OBJ_FILES)
	@rm -f $(OBJ_BONUS_FILES)

fclean: clean
	@make fclean -s -C lib/ft_printf
	@make fclean -s -C lib/libft
	@rm -f so_long
	@rm -f so_long_bonus

# Rebuild
# ============================
re: fclean all

# Cibles "fantômes"
# ============================
.PHONY: all clean fclean re libmlx bonus
