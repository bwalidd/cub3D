#include "mlx.h"
#include <stdlib.h>

typedef struct s_mlx
{
    void *mlx_ptr;
    void *win_ptr;
}t_mlx;

int main()
{
    t_mlx *mlxx;

    mlxx = malloc(sizeof(t_mlx));

    mlxx->mlx_ptr = mlx_init();
    mlxx->win_ptr = mlx_new_window(mlxx->mlx_ptr,800,300,"cub3D");
    mlx_loop(mlxx->mlx_ptr);
}