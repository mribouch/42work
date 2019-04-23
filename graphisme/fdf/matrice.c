/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:36:30 by mribouch          #+#    #+#             */
/*   Updated: 2019/04/19 18:46:21 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mat4	ft_matmult_fline(t_mat4 rot1, t_mat4 rot2, t_mat4 res)
{
	res.d.m00 = rot1.d.m00 * rot2.d.m00 + rot1.d.m01 * rot2.d.m10
		+ rot1.d.m02 * rot2.d.m20 + rot1.d.m03 * rot2.d.m30;
	res.d.m01 = rot1.d.m00 * rot2.d.m01 + rot1.d.m01 * rot2.d.m11
		+ rot1.d.m02 * rot2.d.m21 + rot1.d.m03 * rot2.d.m31;
	res.d.m02 = rot1.d.m00 * rot2.d.m02 + rot1.d.m01 * rot2.d.m12
		+ rot1.d.m02 * rot2.d.m22 + rot1.d.m03 * rot2.d.m32;
	res.d.m03 = rot1.d.m00 * rot2.d.m03 + rot1.d.m01 * rot2.d.m13
		+ rot1.d.m02 * rot2.d.m23 + rot1.d.m03 * rot2.d.m33;
	return (res);
}

static t_mat4	ft_matmult_dline(t_mat4 rot1, t_mat4 rot2, t_mat4 res)
{
	res.d.m10 = rot1.d.m10 * rot2.d.m00 + rot1.d.m11 * rot2.d.m10
		+ rot1.d.m12 * rot2.d.m20 + rot1.d.m13 * rot2.d.m30;
	res.d.m11 = rot1.d.m10 * rot2.d.m01 + rot1.d.m11 * rot2.d.m11
		+ rot1.d.m12 * rot2.d.m21 + rot1.d.m13 * rot2.d.m31;
	res.d.m12 = rot1.d.m10 * rot2.d.m02 + rot1.d.m11 * rot2.d.m12
		+ rot1.d.m12 * rot2.d.m22 + rot1.d.m13 * rot2.d.m32;
	res.d.m13 = rot1.d.m10 * rot2.d.m03 + rot1.d.m11 * rot2.d.m13
		+ rot1.d.m12 * rot2.d.m23 + rot1.d.m13 * rot2.d.m33;
	return (res);
}

static t_mat4	ft_matmult_tline(t_mat4 rot1, t_mat4 rot2, t_mat4 res)
{
	res.d.m20 = rot1.d.m20 * rot2.d.m00 + rot1.d.m21 * rot2.d.m10
		+ rot1.d.m22 * rot2.d.m20 + rot1.d.m23 * rot2.d.m30;
	res.d.m21 = rot1.d.m20 * rot2.d.m01 + rot1.d.m21 * rot2.d.m11
		+ rot1.d.m22 * rot2.d.m21 + rot1.d.m23 * rot2.d.m31;
	res.d.m22 = rot1.d.m20 * rot2.d.m02 + rot1.d.m21 * rot2.d.m12
		+ rot1.d.m22 * rot2.d.m22 + rot1.d.m23 * rot2.d.m32;
	res.d.m23 = rot1.d.m20 * rot2.d.m03 + rot1.d.m21 * rot2.d.m13
		+ rot1.d.m22 * rot2.d.m23 + rot1.d.m23 * rot2.d.m33;
	return (res);
}

static t_mat4	ft_matmult_qline(t_mat4 rot1, t_mat4 rot2, t_mat4 res)
{
	res.d.m30 = rot1.d.m30 * rot2.d.m00 + rot1.d.m31 * rot2.d.m10
		+ rot1.d.m32 * rot2.d.m20 + rot1.d.m33 * rot2.d.m30;
	res.d.m31 = rot1.d.m30 * rot2.d.m01 + rot1.d.m31 * rot2.d.m11
		+ rot1.d.m32 * rot2.d.m21 + rot1.d.m33 * rot2.d.m31;
	res.d.m32 = rot1.d.m30 * rot2.d.m02 + rot1.d.m31 * rot2.d.m12
		+ rot1.d.m32 * rot2.d.m22 + rot1.d.m33 * rot2.d.m32;
	res.d.m33 = rot1.d.m30 * rot2.d.m03 + rot1.d.m31 * rot2.d.m13
		+ rot1.d.m32 * rot2.d.m23 + rot1.d.m33 * rot2.d.m33;
	return (res);
}

t_mat4			ft_multmat2(t_mat4 rot1, t_mat4 rot2)
{
	t_mat4 res;

	res = (t_mat4)(struct s_mat4_data) {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	};
	res = ft_matmult_fline(rot1, rot2, res);
	res = ft_matmult_dline(rot1, rot2, res);
	res = ft_matmult_tline(rot1, rot2, res);
	res = ft_matmult_qline(rot1, rot2, res);
	return (res);
}
