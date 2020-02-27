/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:28:22 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/27 23:28:23 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"


// typedef	struct	s_fdf
// {
// 	int			height;
// 	int			width;
// 	int			**z_matrix;

// 	void		*mlx_ptr;
// 	void		*win_ptr;
// }				t_fdf;

// void	read_file(char *file_name, t_fdf *data);
// void	brasenham(float x, float y, float x1, float y1, t_fdf *data);



// int		deal_key(int key, void *data)
// {
// 	ft_printf("key = %d\n", key);
// 	return (0);
// }
// void	get_line(int **dr)
// {
// 	int *draw;
// 	int x;
// 	int y;

// 	draw = *dr;

// 	x = -100;
// 	y = 100;
// 	while (x < 400)
// 	{
// 		if (x >= 0 && x <= 300 - 1 && y >=0 && y <= 300 - 1)
// 			draw[x + y * 300] = 0xffffff;
// 		x++;
// 		y++;
// 	}
// }

// int		close_endian(void *param)
// {
// 	(void)param;
// 	exit(0);
// }

// int		key_press(int key, void *param)
// {
// 	(void)param;
// 	ft_printf("key = %d\n", key);
// 	if (key == 53)
// 		exit(0);
// 	return (0);
// }


// void	get_width(char *file, t_fdf *fdf)
// {
// 	// int fd;
// 	// char *line;

// 	// fd = open(file, O_RDONLY);
// 	// get_next_line(fd, &line);
// 	// ft_printf("%s\n", line);
// 	// fdf->height = 1;



// 	int		fd;
// 	char	*line;
 
// 	fd = open(file, O_RDONLY, 0); //почему 0??
// 	fdf->width = 0;
// 	get_next_line(fd, &line);
// 	fdf->width = ft_words_num(line, ' ');
// 	free(line);
// 	close(fd);
// }


// void	parse_file(char *file, t_fdf *fdf)
// {
// if (*file == '\n')
// 	fdf->bpp = 0;


// 	// get_width(file, fdf);

// }


// int		main(int ac, char **av)
// {
// 	t_fdf *fdf;

// 	fdf = (t_fdf *)malloc(sizeof(fdf));



// 	if (ac == 2)
// 		parse_file(av[1], fdf);
// 	else
// 		return (0);


// 	int *draw;

// 	fdf->mlx = mlx_init();
// 	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
// 	fdf->img = mlx_new_image(fdf->mlx,  300, 300);

// 	draw = (int *)mlx_get_data_addr(fdf->img, &(fdf->bpp), &(fdf->size_line), &(fdf->endian));

// 	get_line(&draw);
// 	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
// 	mlx_hook(fdf->win, 17, 0, close_endian, 0);
// 	mlx_hook(fdf->win, 2, 0, key_press, 0);

// 	mlx_loop(fdf->mlx);
// 	// t_fdf	*data;
// 	// int i;
// 	// int j;
// 	// data = (t_fdf *)malloc(sizeof(t_fdf));
// 	// read_file(av[1], data);


// 	// data->mlx_ptr = mlx_init();
// 	// data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");

// 	// brasenham(10, 10, 600, 300, data);

// 	// mlx_key_hook(data->win_ptr, deal_key, NULL);
// 	// mlx_loop(mlx_ptr);



// 	// i = 0;
// 	// while (i < data->height)
// 	// {
// 	// 	j = 0;
// 	// 	while (j < data->width)
// 	// 	{
// 	// 		ft_printf("%3d ", data->z_matrix[i][j]);
// 	// 		j++;
// 	// 	}
// 	// 	ft_printf("\n");
// 	// 	i++;
// 	// }


// 	// free(data->z_matrix);
// 	// free(data);
// 	free(fdf);
// 	return (0);
// }

int		validate_file_width(char *file, t_fdf *fdf)
{
	int fd;
	int w;
	char *line;
	int i;

	fd = open(file, O_RDONLY);

	fdf->width = 0;
	return (0);
	i = 1;
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 1)
			fdf->width = ft_strlen(line);
		else if ((int)ft_strlen(line) != fdf->width)
		{
			free(line);
			ft_printf("Widths in file are not equal");
			return (0);
		}
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (1);
}
		
int		validate_file(char *file, t_fdf *fdf)
{
	if (validate_file_width(file, fdf) == 0)
		return (0);
	return (1);
}



int		main(int ac, char **av)
{
	t_fdf fdf;
	if (ac == 2)
	{
		if (validate_file(av[1], &fdf) == 0)
		{
			return (0);
		}

	}

	return (0);
}
