/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_2chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 04:39:14 by coder             #+#    #+#             */
/*   Updated: 2022/02/06 06:23:37 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_count_2chars(const char *s, char c, char b)
{
	size_t	counter;
	size_t	index_c;
	size_t	index_b;

	counter = 0;
	index_c = 0;
	index_b = 0;
	if (!s)
		return (counter);
	while (*(s + index_c))
	{
		if (*(s + index_c) == c)
			counter++;
		index_c++;
	}
	while (*(s + index_b))
	{
		if (*(s + index_b) == b)
			counter++;
		index_b++;
	}
	return (counter);
}
