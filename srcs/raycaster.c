#include "../includes/cub3d.h"
#include <math.h>

t_playerinfo *set_vars_player(t_playerinfo *player)
{
	player->directionx = -1;
	player->directiony = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	return (player);
}	

int	compute_color(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}


//void	basic_raycaster(t_gamestruct *game, t_playerinfo *player)
//{

	//MAKES THE ENTIRE SCREEN WHITE
	// mlx_image_t *new_image = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	// mlx_image_to_window(game->mlx, new_image, 0, 0);
	// int	color = compute_color(255, 255, 255);
	// int y = 0;
	// int	x = 0;
	// while (y < (SCREEN_HEIGHT - 1))
	// {
	// 	x = 0;
	// 	while (x < (SCREEN_WIDTH - 1))
	// 	{
	// 		mlx_put_pixel(new_image, x, y, color);
	// 		x++;
	// 	}
	// 	printf("x = %i\ny = %i\n", x, y);
	// 	y++;
	// }

	//mlx_loop(game->mlx);
	//return ;
//}

void 	draw_line_screen(mlx_image_t *new_image, int x, int drstart, int drend, int colour)
{
	int y = 0;
	while (drstart < drend)
	{
		mlx_put_pixel(new_image, x, drstart, colour);
		drstart++;
	}
}

void	basic_raycaster(t_gamestruct *game, t_playerinfo *player)
{
	int	index;
	double deltaDistX;
	double deltaDistY;
	double sideDistX;
	double sideDistY;
	double mapX;
	double mapY;
	int	color = compute_color(255, 255, 255);
	int	color1 = compute_color(255, 0, 0);
	int	color2 = compute_color(0, 255, 0);
	int	color3 = compute_color(0, 0, 255);
	int colours[4] = {color, color1, color2, color3};
	int	j = 0;
	index = 0;
	player = set_vars_player(player);
	mlx_image_t *new_image = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_image_to_window(game->mlx, new_image, 0, 0);
	while (index < SCREEN_WIDTH)
	{
		player->camerax = 2 * index / (double)SCREEN_WIDTH - 1;
		player->raydir_x = player->directionx + player->plane_x * player->camerax;
		player->raydir_y = player->directiony + player->plane_y * player->camerax;
		mapX = player->player_posx;
		mapY = player->player_posy;

		if (player->raydir_x == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = fabs((float)1 / player->raydir_x);
		if (player->raydir_y == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = fabs((float)1 / player->raydir_y);
			
		double perpWallDist;
      	int stepX;
     	int stepY;
     	int hit = 0; 
      	int side;
	
		if(player->raydir_x < 0)
      	{
        	stepX = -1;
        	sideDistX = (player->player_posx - mapX) * deltaDistX;
      	}
      	else
      	{
      	  stepX = 1;
      	  sideDistX = (mapX + 1.0 - player->player_posx) * deltaDistX;
    	}
    	if(player->raydir_y < 0)
     	{
     	   stepY = -1;
     	   sideDistY = (player->player_posy - mapY) * deltaDistY;
    	}
     	else
     	{
     	   stepY = 1;
     	   sideDistY = (mapY + 1.0 - player->player_posy) * deltaDistY;
     	}

		while(hit == 0)
     	{
       		if(sideDistX < sideDistY)
        	{
        		sideDistX += deltaDistX;
        		mapX += stepX;
        		side = 0;
       		}
        	else
       		{
       		   sideDistY += deltaDistY;
       		   mapY += stepY;
        	   side = 1;
       		}
        	if(game->map[(int)mapX][(int)mapY] == '1')
				hit = 1;
     	}
		
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		int	lineheight = (int)SCREEN_HEIGHT / perpWallDist;
		int drawStart = -lineheight / 2 + SCREEN_HEIGHT / 2;
		if(drawStart < 0) 
			drawStart = 0;
     	int drawEnd = lineheight / 2 + SCREEN_HEIGHT / 2;
		if(drawEnd >= SCREEN_HEIGHT) 
			drawEnd = SCREEN_HEIGHT - 1;
		if (index == 400)
			j++;
		if (index == 600)
			j++;
		if (index == 900)
			j++;
		draw_line_screen(new_image, index, drawStart, drawEnd, colours[j]);
		index++;
	}
	mlx_loop(game->mlx);
	return ;
}