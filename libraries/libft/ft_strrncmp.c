/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:05:40 by coder             #+#    #+#             */
/*   Updated: 2022/01/07 19:05:47 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	while (*(s1 + len_s1 - n) && *(s2 + len_s2 - n) && n != 0
		&& (*(s1 + len_s1 - n) == *(s2 + len_s2 - n)))
		n--;
	if ((*(s1 + len_s1 - n) != *(s2 + len_s2 - n) && n))
		return (*(unsigned char *)(s1 + len_s1 - n)
		- *(unsigned char *)(s2 + len_s2 - n));
	return (0);
}
