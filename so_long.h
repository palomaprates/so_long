#ifndef SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx.h"

# define SQUARE_SIZE 20
# define PLAYER_MARGIN 10
# define EXIT_MARGIN 10
# define SIZE 20

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

typedef struct s_map
{
	int		collectibles;
	int		flag;
	char **map;
}	t_map;

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	char **map;
	int		collectibles;
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

t_map	copy_map(t_data data);

char	*ft_strdup(const char *s);

/*==================================MAP CHECK===================================*/

int	get_amount_lines(char **lines_map);

char	**get_lines_map(int fd);

int	is_map_enclosed(char **lines_map);

int	is_retangular_map(char **lines_map);

int	number_of_elements(char **lines_map, char c);

int	parsing_map(t_data data);

int	check_path(t_data data, int x, int line);

static void	dfs(t_map *map, int x, int line);

/*====================================PRINT===================================*/

void	print_image(t_image *canva, t_image *image, int x, int y);

void	print_avatar(t_image *canva, t_sprite player);

void	print_element(t_image *canva, char **map, char c, t_image *img);

// void	print_exit(t_image *canva, t_image *image, int x, int y);
void	print_exit(t_data *param);

/*====================================IMAGE CONTROL===================================*/

void	destroy_images(t_data *data);

void	init_images(t_data *data);

void	set_image(t_image *image, void *mlx, char *source, int *endian);

/*=========================================GAME CONTROL========================================*/

int	keys_hook(int key_code, t_data *param);

int	close_win(t_data *param);

void	game_images(t_data *param);

void	my_mlx_pixel_put(t_image *data, int x, int y, int color);

int	get_pixel_canva(t_image *image, int x, int y);

char	*touch_element(int player_x, int player_y, char **map);

void	get_avatar_position(t_sprite *player, t_sprite *exit, char **map);

void	move_up(int key_code, t_data *param);

void	move_down(int key_code, t_data *param);

void	move_left(int key_code, t_data *param);

void	move_right(int key_code, t_data *param);

void	movements(int key_code, t_data *param);
#endif
