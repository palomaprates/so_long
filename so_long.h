#ifndef SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx.h"

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct s_sprite{
	int	x;
	int	y;
	int	width;
	int	height;
	t_image	image;
}						t_sprite;

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	char	**map;
	t_image	background;
	t_image	wall;
	t_image	canva;
	t_image	coins;
	t_sprite	player;
	t_sprite	enemy;
	t_sprite	exit;
} 				t_data;



	enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	WALL = '1',
	BACKGROUND = '0',
	COINS = 'C',
	EXIT = 'E',
	PLAYER = 'P',
};

/*===================================UTILS=======================================*/

char	**ft_split(char const *s, char c);

char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);

int	ft_strlen(char *str);

char	*get_next_line(int fd);

void	to_clear_buffer(char *s1);

int	to_find_newline(char *str);

/*==================================MAP CHECK===================================*/

int	get_amount_lines(char **lines_map);

int	get_elements_position(char **map, char c);

char	**get_lines_map(int fd);

int	is_map_enclosed(char **lines_map);

int	is_retangular_map(char **lines_map);

int	len_map(char **lines_map);

int	number_of_elements(char **lines_map, char c);

int	parsing_map(char **lines_map);

/*====================================PRINT===================================*/

void	print_image(t_image *canva, t_image *image, int x, int y);

void	print_avatar(t_image *canva, t_sprite player);

void	print_element(t_image *canva, char **map, char c, t_image *img);

/*====================================IMAGE CONTROL===================================*/

void	destroy_images(t_data *data);

void	init_images(t_data *data);

/*=========================================KEYS========================================*/

int	keys_hook(int key_code, t_data *param);

int	close_win(t_data *param);

void	my_mlx_pixel_put(t_image *data, int x, int y, int color);

int	get_pixel_canva(t_image *image, int x, int y);

#endif