/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 04:39:14 by coder             #+#    #+#             */
/*   Updated: 2022/02/05 04:39:15 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_char(const char *s, char c)
{
	size_t	counter;
	size_t	index;

	counter = 0;
	index = 0;
	if (!s)
		return (counter);
	while (*(s + index))
	{
		if (*(s + index) == c)
			counter++;
		index++;
	}
	return (counter);
}
