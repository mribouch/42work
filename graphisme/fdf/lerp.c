/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:57:45 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/01 14:27:53 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "fdf.h"
#include <stdio.h>


int ft_lerp(int i, int color1, int color2, float nbp)
{
    t_color c1;
    t_color c2;
    t_color c3;
    int ret;

    c1.r = (color1 & 0xFF0000) >> 16;
    c1.g = (color1 & 0x00FF00) >> 8;
    c1.b = (color1 & 0x0000FF);
    c2.r = (color2 & 0xFF0000) >> 16;
    c2.g = (color2 & 0x00FF00) >> 8;
    c2.b = (color2 & 0x0000FF);

    c3.r = c1.r + (c2.r - c1.r) * (i - 0) / (nbp - 0);
    c3.g = c1.g + (c2.g - c1.g) * (i - 0) / (nbp - 0);
    c3.b = c1.b + (c2.b - c1.b) * (i - 0) / (nbp - 0);
    ret = (c3.b << 0) | (c3.g << 8) | (c3.r << 16);
    //printf("%X\n", ret);
    return (ret);
}