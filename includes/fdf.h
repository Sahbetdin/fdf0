
#ifndef FDF_H
# define FDF_H

/*
** ------ LIBRARIES ------
*/
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

# define WIDTH 1900
# define HEIGHT 1200

typedef struct s_fdf
{
	void    *mlx;
	void    *win;
	void	*img;

	int     bpp;
	int     size_line;
	int     endian;
	int		width;
	int		height;


}   t_fdf;


#endif
