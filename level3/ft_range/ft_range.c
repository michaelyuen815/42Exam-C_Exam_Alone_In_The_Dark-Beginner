/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:49:38 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/06 15:01:34 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	size_t	len;
	int		sign;
	int		*ret;

	len = ((end > start) ? (end - start + 1) : (start - end + 1));
	sign = (end > start);
	if(!(ret = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	while (len--)
		ret[len] = (sign ? (start + (int)len) : (start - (int)len));
	return (ret);
}
