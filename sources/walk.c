/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:52:41 by coder             #+#    #+#             */
/*   Updated: 2022/02/03 04:36:55 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_steps(int *n_steps)
{
	(*n_steps)++;
	printf("You walked %d steps\n", *n_steps);
	return ;
}

int	walk(int keysym, t_run_prog *run)
{
	if (keysym == XK_Right || keysym == XK_d || keysym == XK_D)
	{
		run->map.player.x++;
		return (TRUE);
	}
	if (keysym == XK_Left || keysym == XK_a || keysym == XK_A)
	{
		run->map.player.x--;
		return (TRUE);
	}
	if (keysym == XK_Up || keysym == XK_w || keysym == XK_W)
	{
		run->map.player.y--;
		return (TRUE);
	}
	if (keysym == XK_Down || keysym == XK_s || keysym == XK_S)
	{
		run->map.player.y++;
		return (TRUE);
	}
	return (FALSE);
}
