#include "../includes/fdf.h"

float	abs_val_float(float a, float b)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

float	max_val_float(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	brasenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float x_step;
	float y_step;
	float max_;

	x_step = x1 - x;
	y_step = y1 - y;

	max_ = max_val_float(abs_val_float(x_step), abs_val_float(y_step));
	x_step = x_step / max_;
	y_step = y_step / max_;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}









}


















