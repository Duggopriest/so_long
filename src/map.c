#include "so_long.h"
#include "get_next_line.h"

//ground;
//obj;
//exit;
//wall;
t_textures	*grab_textures(t_render *render)
{
	t_textures	*t;

	t = malloc(sizeof(t));
	t->player = mlx_xpm_file_to_image(render->vars->mlx,
			"../textures/player.xpm", &t->player->w, &t->player->h);
	return (t);
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
		if (!new->grid[new->h] || new->h >= 100)
			break ;
		new->h++;
	}
	new->w = ft_strlen(&new->grid[0][0]);
	return (new);
}

//mlx_put_image_to_window(r->vars->mlx, r->vars->mlx_win, r->img->img, , int y );
t_map	*build_tiles(char *file, char *map, t_render *r)
{
	t_map		*m;
	t_textures	*t;
	t_v2		player_pos;
	int			i;
	int			j;

	m = malloc(sizeof(m));
	m->grid = grab_grid(map);
	m->ti = malloc((m->grid->h * m->grid->w) * sizeof(t_tile));
	t = grab_textures(r);
	j = 0;
	while (j < m->grid->h)
	{
		i = 0;
		while(i < m->grid->w)
		{
			if (m->grid->grid[j][i] == p)
			{
				m->ti[i][j].img = t->player;
				player_pos.x = i;
				player_pos.y = j;
			}
			else if (m->grid->grid[j][i] == '1')
				m->ti[i][j].img = t->wall;
			else if (m->grid->grid[j][i] == '0')
				m->ti[i][j].img = t->ground;
			else if (m->grid->grid[j][i] == 'C')
				m->ti[i][j].img = t->obj;
			else if (m->grid->grid[j][i] == 'E')
				m->ti[i][j].img = t->exit;
		}
		j++;
	}
}
