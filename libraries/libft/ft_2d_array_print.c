/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_array_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 05:25:35 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 08:39:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_2d_array_print(char **matrix, int width, int height)
{
	int	len_array;
	int	i_matrix;
	int	i_array;

	i_matrix = 0;
	i_array = 0;
	len_array = width;
	printf("\n");
	while (i_matrix < height)
	{
		while (i_array < len_array)
		{
			printf("%c", matrix[i_matrix][i_array]);
			i_array++;
		}
		i_array = 0;
		i_matrix++;
		printf("\n");
	}
	return (1);
}
