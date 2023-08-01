# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 17:38:49 by hsebille          #+#    #+#              #
#    Updated: 2023/08/01 13:33:15 by laprieur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	cub3D

# **************************************************************************** #
#                                 INGREDIENTS                                  #
# **************************************************************************** #

MANDATORY		:=	mandatory/gameplay/g_hooks.c				\
					mandatory/gameplay/g_utils.c				\
					mandatory/init/i_colors.c					\
					mandatory/init/i_data.c						\
					mandatory/init/i_images.c					\
					mandatory/init/i_mlx.c						\
					mandatory/init/i_player.c					\
					mandatory/init/i_screen.c					\
					mandatory/init/i_textures.c					\
					mandatory/parsing/p_all.c					\
					mandatory/parsing/p_colors.c				\
					mandatory/parsing/p_file.c					\
					mandatory/parsing/p_map.c					\
					mandatory/parsing/p_texture.c				\
					mandatory/parsing/p_utils.c					\
					mandatory/raycasting/r_raycasting.c			\
					mandatory/raycasting/r_utils_bis.c			\
					mandatory/raycasting/r_utils.c				\
					mandatory/textures/t_textures.c				\
					mandatory/textures/t_utils.c				\
					mandatory/utils/u_list.c					\
					mandatory/main.c							\

LIBFT			:=	libft/libft.a

MINILIBX		:=	minilibx/build/libmlx42.a

M_OBJS			:=	$(MANDATORY:%.c=.build/%.o)
DEPS			:=	$(M_OBJS:%.o=%.d)

CC				:=	clang
CFLAGS			:=	-Wall -Wextra -Werror -Ofast -g
CPPFLAGS		:=	-MP -MMD -Iinclude -Ilibft/include -Iminilibx/include
LDFLAGS			:=	-Llibft -lft -L$(dir $(MINILIBX)) -lmlx42 -ldl -lglfw -pthread -lm

# **************************************************************************** #
#                                    TOOLS                                     #
# **************************************************************************** #

MAKEFLAGS		+= --silent --no-print-directory

# **************************************************************************** #
#                                   RECIPES                                    #
# **************************************************************************** #

all: header $(LIBFT) $(NAME) 

$(NAME): $(M_OBJS) | $(MINILIBX)
	$(CC) $(CFLAGS) $(MINILIBX) $(M_OBJS) $(LDFLAGS) -o $(NAME)
	@printf "%b" "$(BLUE)CREATED $(CYAN)$(NAME)\n"

$(LIBFT):
	$(MAKE) -C $(dir $@)

$(MINILIBX):
	cd minilibx && cmake -B build
	make -C $(dir $@)

.build/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@
	@printf "%b" "$(BLUE)CREATED $(CYAN)$@\n"

-include $(DEPS)

clean:
	$(MAKE) -C libft clean
	rm -rf .build

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)
	rm -rf $(dir $(MINILIBX))

re:
	$(MAKE) fclean
	$(MAKE) all

# **************************************************************************** #
#                                    STYLE                                     #
# **************************************************************************** #

GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
CYAN			:= \033[0;36m
OFF				:= \033[m

header:
	@printf "%b" "$(GREEN)"
	@echo "			   _    _____     _				   "
	@echo "		 ___ _   _| |__|___ /  __| |		   "
	@echo "	   	/ __| | | |  _ \ |_ \ / _  |		   "
	@echo "               | (__| |_| | |_) |__) | (_| |"
	@echo "		\___|\____|____/____/ \____|		   "
	@echo "		   by hsebille & laprieur		   "
	@echo
	@printf "%b" "$(CYAN)CC:	$(YELLOW)$(CC)\n"
	@printf "%b" "$(CYAN)CFlags:	$(YELLOW)$(CFLAGS)\n"
	@printf "%b" "$(OFF)"
	@echo

# **************************************************************************** #
#                                   SPECIAL                                    #
# **************************************************************************** #

.PHONY: all clean fclean re $(LIBFT)
.DELETE_ON_ERROR:
