CFLAGS = #-Wall -Wextra -Werror

SRCS =	main/main.c							\
			utils/count_words.c				\
			utils/ft_free.c					\
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

			
OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all