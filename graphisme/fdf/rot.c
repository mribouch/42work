/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:31:31 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/20 19:05:08 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

//0.785398
//0.174533

t_point     *ft_rotx(t_window *infos)
{
    int     i;
    float   x;
    float   y;
    float   z;
    float rot[4][4] = {{1 , 0, 0, 0},
                    {0, cos(infos->state->rota.x), -sin(infos->state->rota.x), 0},
                    {0, sin(infos->state->rota.x), cos(infos->state->rota.x), 0},
                    {0, 0, 0, 1}};
    i = 0;
    x = 0;
    y = 0;
    z = 0;
    while (i < infos->mapinf->height * infos->mapinf->width)
    {
        x = rot[0][0] * infos->iso[i].x + rot[0][1] * infos->iso[i].y + rot[0][2] * infos->iso[i].z + rot[0][3] * 1;
        y = rot[1][0] * infos->iso[i].x + rot[1][1] * infos->iso[i].y + rot[1][2] * infos->iso[i].z + rot[1][3] * 1;
        z = rot[2][0] * infos->iso[i].x + rot[2][1] * infos->iso[i].y + rot[2][2] * infos->iso[i].z + rot[2][3] * 1;
        infos->iso[i].x = x;
        infos->iso[i].y = y;
        infos->iso[i].z = z;
        i++;
    }
    return (infos->iso);
}

t_point    *ft_roty(t_window *infos)
{
    int     i;
    float   x;
    float   y;
    float   z;
    float rot[4][4] = {{cos(infos->state->rota.y) , 0, sin(infos->state->rota.y), 0},
                    {0, 1, 0, 0},
                    {-sin(infos->state->rota.y), 0, cos(infos->state->rota.y), 0},
                    {0, 0, 0, 1}};
    i = 0;
    while (i < infos->mapinf->height * infos->mapinf->width)
    {
        x = rot[0][0] * infos->iso[i].x + rot[0][1] * infos->iso[i].y + rot[0][2] * infos->iso[i].z + rot[0][3] * 1;
        y = rot[1][0] * infos->iso[i].x + rot[1][1] * infos->iso[i].y + rot[1][2] * infos->iso[i].z + rot[1][3] * 1;
        z = rot[2][0] * infos->iso[i].x + rot[2][1] * infos->iso[i].y + rot[2][2] * infos->iso[i].z + rot[2][3] * 1;
        infos->iso[i].x = x;
        infos->iso[i].y = y;
        infos->iso[i].z = z;
        i++;
    }
    return (infos->iso);
}

t_point     *ft_rotz(t_window *infos)
{
    int     i;
    float   x;
    float   y;
    float   z;
    float   rot[4][4] = {{cos(infos->state->rota.z) , sin(infos->state->rota.z), 0, 0},
                    {-sin(infos->state->rota.z), cos(infos->state->rota.z), 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}};

    i = 0;
    while (i < infos->mapinf->height * infos->mapinf->width)
    {
        x = rot[0][0] * infos->iso[i].x + rot[0][1] * infos->iso[i].y + rot[0][2] * infos->iso[i].z + rot[0][3] * 1;
        y = rot[1][0] * infos->iso[i].x + rot[1][1] * infos->iso[i].y + rot[1][2] * infos->iso[i].z + rot[1][3] * 1;
        z = rot[2][0] * infos->iso[i].x + rot[2][1] * infos->iso[i].y + rot[2][2] * infos->iso[i].z + rot[2][3] * 1;
        infos->iso[i].x = x;
        infos->iso[i].y = y;
        infos->iso[i].z = z;
        i++;
    }
    return (infos->iso);
}

/*t_point     *ft_rotxdown(t_window *infos)
{
    int     i;
    float   x;
    float   y;
    float   z;
    float rot[4][4] = {{1 , 0, 0, 0},
                        {0, cos(0.174533), sin(0.174533), 0},
                        {0, -sin(0.174533), cos(0.174533), 0},
                        {0, 0, 0, 1}};
    i = 0;
    //ft_bzero(infos->img, (infos->height * infos->width) * sizeof(int));
    while (i < infos->mapinf->height * infos->mapinf->width)
    {
        x = rot[0][0] * infos->iso[i].x + rot[0][1] * infos->iso[i].y + rot[0][2] * infos->iso[i].z + rot[0][3] * 1;
        y = rot[1][0] * infos->iso[i].x + rot[1][1] * infos->iso[i].y + rot[1][2] * infos->iso[i].z + rot[1][3] * 1;
        z = rot[2][0] * infos->iso[i].x + rot[2][1] * infos->iso[i].y + rot[2][2] * infos->iso[i].z + rot[2][3] * 1;
        infos->iso[i].x = x;
        infos->iso[i].y = y;
        infos->iso[i].z = z;
        i++;
    }
    return (infos->iso);
}*/

/*t_point     *ft_rotxup(t_window *infos)
{
    ft_putstr("gbfdhgwher");
    int     i;
    float   x;
    float   y;
    float   z;
    float rot[4][4] = {{1 , 0, 0, 0},
                    {0, cos(infos->state->rota.x), -sin(infos->state->rota.x), 0},
                    {0, sin(infos->state->rota.x), cos(infos->state->rota.x), 0},
                    {0, 0, 0, 1}};
    i = 0;
    x = 0;
    y = 0;
    z = 0;
    ft_putendl("-----------------------");
    ft_putstr("infos->state->rota.x = ");
    ft_putnbr(infos->state->rota.x);
    ft_putchar('\n');
    //ft_bzero(infos->img, (infos->height * infos->width) * sizeof(int));
    while (i < infos->mapinf->height * infos->mapinf->width)
    {
        x = rot[0][0] * infos->iso[i].x + rot[0][1] * infos->iso[i].y + rot[0][2] * infos->iso[i].z + rot[0][3] * 1;
        y = rot[1][0] * infos->iso[i].x + rot[1][1] * infos->iso[i].y + rot[1][2] * infos->iso[i].z + rot[1][3] * 1;
        z = rot[2][0] * infos->iso[i].x + rot[2][1] * infos->iso[i].y + rot[2][2] * infos->iso[i].z + rot[2][3] * 1;
        infos->iso[i].x = x;
        infos->iso[i].y = y;
        infos->iso[i].z = z;
        i++;
        ft_putstr("infos->iso[i].x = ");
        ft_putnbr(infos->iso[i].x);
        ft_putchar('\n');
        ft_putstr("infos->iso[i].y = ");
        ft_putnbr(infos->iso[i].y);
        ft_putchar('\n');
        ft_putstr("infos->iso[i].z = ");
        ft_putnbr(infos->iso[i].z);
        ft_putchar('\n');
    }
    return (infos->iso);
}*/

/*t_point    *ft_rotyright(t_window *infos)
{
    int     i;
    float   x;
    float   y;
    float   z;
    float rot[4][4] = {{cos(0.174533) , 0, sin(0.174533), 0},
                    {0, 1, 0, 0},
                    {-sin(0.174533), 0, cos(0.174533), 0},
                    {0, 0, 0, 1}};
    i = 0;
    ft_putstr("couciu");
   // ft_bzero(infos->img, (infos->height * infos->width) * sizeof(int));
    while (i < infos->mapinf->height * infos->mapinf->width)
    {
        x = rot[0][0] * infos->iso[i].x + rot[0][1] * infos->iso[i].y + rot[0][2] * infos->iso[i].z + rot[0][3] * 1;
        y = rot[1][0] * infos->iso[i].x + rot[1][1] * infos->iso[i].y + rot[1][2] * infos->iso[i].z + rot[1][3] * 1;
        z = rot[2][0] * infos->iso[i].x + rot[2][1] * infos->iso[i].y + rot[2][2] * infos->iso[i].z + rot[2][3] * 1;
        infos->iso[i].x = x;
        infos->iso[i].y = y;
        infos->iso[i].z = z;
        i++;
    }
    return (infos->iso);
}

t_point    *ft_rotyleft(t_window *infos)
{
    int i;
    float   x;
    float   y;
    float   z;
    float rot[4][4] = {{cos(0.174533) , 0, -sin(0.174533), 0},
                    {0, 1, 0, 0},
                    {sin(0.174533), 0, cos(0.174533), 0},
                    {0, 0, 0, 1}};
    i = 0;
    ft_bzero(infos->img, (infos->height * infos->width) * sizeof(int));
    while (i < infos->mapinf->height * infos->mapinf->width)
    {
        x = rot[0][0] * infos->vertices[i].x + rot[0][1] * infos->vertices[i].y + rot[0][2] * infos->vertices[i].z + rot[0][3] * 1;
        y = rot[1][0] * infos->vertices[i].x + rot[1][1] * infos->vertices[i].y + rot[1][2] * infos->vertices[i].z + rot[1][3] * 1;
        z = rot[2][0] * infos->vertices[i].x + rot[2][1] * infos->vertices[i].y + rot[2][2] * infos->vertices[i].z + rot[2][3] * 1;
        infos->iso[i].x = x;
        infos->iso[i].y = y;
        infos->iso[i].z = z;
        i++;
    }
    return (infos->iso);
}


t_point *ft_rotzleft(t_window *infos)
{
    int     i;
    float   x;
    float   y;
    float   z;
    float   rot[4][4] = {{cos(0.785398) , -sin(0.785398), 0, 0},
                    {sin(0.785398), cos(0.785398), 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}};

    i = 0;
    //ft_bzero(infos->img, (infos->height * infos->width) * sizeof(int));
    while (i < infos->mapinf->height * infos->mapinf->width)
    {
        x = rot[0][0] * infos->vertices[i].x + rot[0][1] * infos->vertices[i].y + rot[0][2] * infos->vertices[i].z + rot[0][3] * 1;
        y = rot[1][0] * infos->vertices[i].x + rot[1][1] * infos->vertices[i].y + rot[1][2] * infos->vertices[i].z + rot[1][3] * 1;
        z = rot[2][0] * infos->vertices[i].x + rot[2][1] * infos->vertices[i].y + rot[2][2] * infos->vertices[i].z + rot[2][3] * 1;
        infos->iso[i].x = x;
        infos->iso[i].y = y;
        infos->iso[i].z = z;
        i++;
    }
    return (infos->iso);
}

t_point *ft_rotzright(t_window *infos)
{
    int     i;
    float   x;
    float   y;
    float   z;
    float   rot[4][4] = {{cos(0.785398) , sin(0.785398), 0, 0},
                    {-sin(0.785398), cos(0.785398), 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}};

    i = 0;
    //ft_bzero(infos->img, (infos->height * infos->width) * sizeof(int));
    while (i < infos->mapinf->height * infos->mapinf->width)
    {
        x = rot[0][0] * infos->vertices[i].x + rot[0][1] * infos->vertices[i].y + rot[0][2] * infos->vertices[i].z + rot[0][3] * 1;
        y = rot[1][0] * infos->vertices[i].x + rot[1][1] * infos->vertices[i].y + rot[1][2] * infos->vertices[i].z + rot[1][3] * 1;
        z = rot[2][0] * infos->vertices[i].x + rot[2][1] * infos->vertices[i].y + rot[2][2] * infos->vertices[i].z + rot[2][3] * 1;
        infos->iso[i].x = x;
        infos->iso[i].y = y;
        infos->iso[i].z = z;
        i++;
    }
    return (infos->iso);
}*/