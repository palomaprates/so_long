#include "../so_long.h"

void free_lines_map(char **map)
{
    int i = 0;
    if (!map)
        return;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void cleanup(t_data *data)
{
    if (data->mlx_win)
        mlx_destroy_window(data->mlx, data->mlx_win);
    mlx_destroy_image(data->mlx, data->background.img);
    mlx_destroy_image(data->mlx, data->wall.img);
    mlx_destroy_image(data->mlx, data->canva.img);
    mlx_destroy_image(data->mlx, data->coins.img);
    mlx_destroy_image(data->mlx, data->player.image.img);
    mlx_destroy_image(data->mlx, data->exit.image.img);
    if (data->map)
        free_lines_map(data->map);
}

void cleanup_and_exit(t_data *data)
{
    cleanup(data);
    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx);
    }
    exit(0);
}
