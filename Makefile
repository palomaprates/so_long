CFLAGS = #-Wall -Wextra -Werror

SRCS =	main/main.c							\
			utils/ft_split.c					\
			utils/ft_strjoin.c				\
			utils/ft_strlcpy.c				\
			utils/ft_strlen.c					\
			utils/get_next_line.c			\
			utils/to_clear_buffer.c			\
			utils/to_find_newline.c			\
			map_check/get_amount_lines.c	\
			map_check/get_lines_map.c		\
			map_check/is_map_enclosed.c	\
			map_check/is_retangular_map.c	\
			map_check/number_of_elements.c	\
			map_check/parsing_map.c			\
			map_check/len_map.c					\
			game_control/keys_hook.c			\
			game_control/close_win.c						\
			game_control/game_images.c				\
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
			
OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -L/opt/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all