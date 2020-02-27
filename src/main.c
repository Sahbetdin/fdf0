
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
void	get_line(int **dr)
{
	int *draw;
	int x;
	int y;

	draw = *dr;

	x = 100;
	y = 100;
	while (x < 200)
	{
		draw[x + y * HEIGHT] = 0xffffff;
		x++;
		y++;
	}
	// *dr[101 + 100 * 600] = 0xffffff;
	// *dr[102 + 100 * 600] = 0xffffff;
	// *dr[103 + 100 * 600] = 0xffffff;
	// *dr[104 + 100 * 600] = 0xffffff;
	// *dr[105 + 100 * 600] = 0xffffff;
	// *dr[106 + 100 * 600] = 0xffffff;
	// *dr[107 + 100 * 600] = 0xffffff;
	// *dr[108 + 100 * 600] = 0xffffff;
	// *dr[109 + 100 * 600] = 0xffffff;
	// *dr[110 + 100 * 600] = 0xffffff;
	// *dr[111 + 100 * 600] = 0xffffff;
}

int		close_endian(void *param)
{
	(void)param;
	exit(0);
}


int		main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	void	*img;
	int bpp;
	int size_line;
	int endian;

	int *draw;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "fdf");
	img = mlx_new_image(mlx, 300, 300);
	draw = (int *)mlx_get_data_addr(img, &bpp, &size_line, &endian);

	get_line(&draw);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_hook(win, 17, 0, close_endian, 0);
	mlx_loop(mlx);
	// t_fdf	*data;
	// int i;
	// int j;
	// ac = 1;
	if (av[0][0] == '\n')
		ac = 2;

	// data = (t_fdf *)malloc(sizeof(t_fdf));
	// read_file(av[1], data);


	// data->mlx_ptr = mlx_init();
	// data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");

	// brasenham(10, 10, 600, 300, data);

	// mlx_key_hook(data->win_ptr, deal_key, NULL);
	// mlx_loop(mlx_ptr);



	// i = 0;
	// while (i < data->height)
	// {
	// 	j = 0;
	// 	while (j < data->width)
	// 	{
	// 		ft_printf("%3d ", data->z_matrix[i][j]);
	// 		j++;
	// 	}
	// 	ft_printf("\n");
	// 	i++;
	// }


	// free(data->z_matrix);
	// free(data);

	return (0);
}