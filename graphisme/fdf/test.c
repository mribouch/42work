/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:23:53 by mribouch          #+#    #+#             */
/*   Updated: 2019/03/01 13:46:56 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int ft_lerp(int i, int color1, int color2, int nbp)
{
    t_color *c1;
    t_color *c2;
    t_color *c3;
    int ret;

    if (!(c1 = malloc(sizeof(t_color))))
        return (0);
    if (!(c2 = malloc(sizeof(t_color))))
        return (0);
    if (!(c3 = malloc(sizeof(t_color))))
        return (0);
    c1->r = (color1 & 0xFF0000) >> 16;
    c1->g = (color1 & 0x00FF00) >> 8;
    c1->b = (color1 & 0x0000FF);
    c2->r = (color2 & 0xFF0000) >> 16;
    c2->g = (color2 & 0x00FF00) >> 8;
    c2->b = (color2 & 0x0000FF);

    (void)nbp;
    (void)i;

    c3->r = c1->r + (c2->r - c1->r) * (i - 0) / (nbp - 0);
    c3->g = c1->g + (c2->g - c1->g) * (i - 0) / (nbp - 0);
    c3->r = c1->b + (c2->b - c1->b) * (i - 0) / (nbp - 0);

    //ret = (c3->b << 0) | (c3->g << 8) | (c3->r << 16);
    ret = (c3->b << 0) | (c3->g << 8) | (c3->r << 16);
    ft_putstr(" r2 = ");
    printf("%X\n", c2->r);
    ft_putstr(" g2 = ");
    printf("%X\n", c2->g);
    ft_putstr(" b2 = ");
    printf("%X\n", c2->b);
    ft_putstr(" r3 = ");
    printf("%X\n", c3->r);
    ft_putstr(" g3 = ");
    printf("%X\n", c3->g);
    ft_putstr(" b3 = ");
    printf("%X\n", c3->b);
    ft_putstr(" ret ");
    printf("%X\n", ret);
    return (ret);
}

int main(void)
{
    ft_lerp(2, 0xFFCCE5, 0xCC00, 10);
    return (0);
}