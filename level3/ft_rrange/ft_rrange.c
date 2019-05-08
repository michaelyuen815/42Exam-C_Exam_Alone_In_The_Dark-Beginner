/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:39:48 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/06 14:45:15 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	size_t	len;
	int		sign;
	int		*ret;

	len = ((end > start) ? (end - start + 1) : (start - end + 1));
	sign = (end > start);
	if(!(ret = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	while (len--)
		ret[len] = (sign ? (end - (int)len): (end + (int)len));
	return (ret);
}
