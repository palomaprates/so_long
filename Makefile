CFLAGS = -Wall -Wextra -Werror

SRCS =	main/main.c							\
			utils/ft_split.c					\
			utils/ft_strjoin.c				\
			utils/ft_strlcpy.c				\
			utils/ft_strlen.c					\
			utils/get_next_line.c			\
			utils/to_clear_buffer.c			\
			utils/to_find_newline.c			\
			utils/copy_map.c					\
			utils/ft_strdup.c					\
			map_check/get_amount_lines.c	\
			map_check/get_lines_map.c		\
			map_check/is_map_enclosed.c	\
			map_check/is_retangular_map.c	\
			map_check/number_of_elements.c	\
			map_check/parsing_map.c			\
			map_check/check_path.c				\
			game_control/keys_hook.c			\
			game_control/close_win.c						\
			game_control/game_images.c				\
			game_control/get_avatar_position.c	\
			game_control/cleanup_and_exit.c				\
			print/print_avatar.c	\
			print/print_image.c		\
			print/print_element.c		\
			print/print_exit.c			\
			get_pixel_canva.c						\
			my_mlx_pixel_put.c					\
			image_control/destroy_images.c	\
			image_control/init_images.c		\
			image_control/set_image.c	\
			game_movements/movements.c			\
			touch_element.c						\
			
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME) 

$(FT_PRINTF_LIB):
	@make -s -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(FT_PRINTF_DIR) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS) $(FT_PRINTF_LIB)
	$(CC) $(OBJS) $(FT_PRINTF_LIB) minilibx-linux/libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJS)
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all