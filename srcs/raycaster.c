#include "../includes/cub3d.h"
#include <math.h>

//With this function the goal is having a different player view when the user select a different
//spawn direction.
t_playerinfo *set_vars_player(t_playerinfo *player)
{
	if (player->start_direction == 'N')
	{
		player->directionx = -1;
		player->directiony = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (player->start_direction == 'S')
	{
		player->directionx = 1;
		player->directiony = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->start_direction == 'E')
	{
		player->directionx = 0;
		player->directiony = -1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (player->start_direction == 'W')
	{
		player->directionx = 0;
		player->directiony = 1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	return (player);
}

void 	draw_line_screen(mlx_image_t *new_image, int x, int drstart, int drend, int colour, t_gamestruct *game)
{
	int	count;

	count = 0;
	if (drstart > 0)
	{
		while (count < drstart)
		{
			mlx_put_pixel(new_image, x, count, game->ceiling_rgb);
			count++;
		}
	}
	while (drstart < drend)
	{
		mlx_put_pixel(new_image, x, drstart, colour);
		drstart++;
	}
	if (drend < SCREEN_HEIGHT - 1)
	{
		while (drend < SCREEN_HEIGHT - 1)
		{
			mlx_put_pixel(new_image, x, drend, game->floor_rgb);
			drend++;
		}
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
	int	color = transfer_colour(255, 255, 255);
	int	color1 = transfer_colour(255, 0, 0);
	int	color2 = transfer_colour(0, 255, 0);
	int	color3 = transfer_colour(0, 0, 255);
	int colours[4] = {color, color1, color2, color3};
	int	j = 0;
	index = 0;
	player = set_vars_player(player);
	if (!game->raycaster_img)
	{
		game->raycaster_img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
		mlx_image_to_window(game->mlx, game->raycaster_img, 0, 0);
	}
	else
	{
		mlx_delete_image(game->mlx, game->raycaster_img);
		game->raycaster_img = NULL;
		game->raycaster_img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
		mlx_image_to_window(game->mlx, game->raycaster_img, 0, 0);			
	}
	while (index < SCREEN_WIDTH)
	{
		player->camerax = 2 * index / (double)SCREEN_WIDTH - 1;
		player->raydir_x = player->directionx + player->plane_x * player->camerax;
		player->raydir_y = player->directiony + player->plane_y * player->camerax;
		
		mapX = player->player_posx - 0.5; //if i want the camera to be centered
		mapY = player->player_posy - 0.5; //if i want the camera to be centered 

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
        	if(game->map[(int)mapY][(int)mapX] == '1')
			{
				hit = 1;
				if ((mapY - 1 > 0) && (game->map[(int)(mapY - 1)][(int)mapX] == '0'))
					j = 0;
				else if ((mapY + 1 < get_max_2d(game->map)) && (game->map[(int)(mapY + 1)][(int)mapX] == '0'))
					j = 1;
				else if ((mapX - 1 > 0) && (game->map[(int)mapY][(int)(mapX - 1)] == '0'))
					j = 2;
				else if ((mapX + 1 < ft_strlen(game->map[(int)mapY])) && (game->map[(int)mapY][(int)(mapX + 1)] == '0'))
					j = 3;
			}
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
		draw_line_screen(game->raycaster_img, index, drawStart, drawEnd, colours[j], game);
		index++;
	}
	return ;
}