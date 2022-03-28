#include "so_long.h"
#include "get_next_line.h"

//ground;
//obj;
//goal;
//wall;
t_textures	*grab_textures(t_render *render)
{
	t_textures	textures;

	textures.player = mlx_xpm_file_to_image(render->vars->mlx,
			"../textures/player.xpm", &textures.player->w, &textures.player->h);
	return (&textures);
}

t_grid	*grab_grid(char	*path)
{
	t_grid	*new;
	int		fd;
	char	*str;

	new = malloc(sizeof(new));
	new->grid = malloc(100 * sizeof(new->grid));
	fd = open(path, O_RDONLY);
	while (1)
	{
		new->grid[new->h] = get_next_line(fd);
		if (!new->grid[new->h])
			break ;
		new->h++;
	}
	new->w = ft_strlen(&new->grid[0][0]);
	return (new);
}

t_map	*build_map(char *file)
{
	t_map	map;
	t_v2	player_pos;
}
