/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:03:33 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/06 13:16:24 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define OCT "0123456789ABCDEF"

char	*ft_itoa_base(int value, int base)
{
	size_t	i;
	size_t	len;
	int		sign;
	char	tmp[130];
	char	*ret;

	len = 0;
	sign = (value < 0 ? -1 : 1);
	if (value == 0)
		tmp[len++] = '0';
	while (value)
	{
		tmp[len++] = OCT[value % base * sign];
		value /= base;
	}
	if (sign == -1 && base == 10)
		tmp[len++] = '-';
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = 0;
	i = -1;
	while (++i < len)
		ret[i] = tmp[len - 1 - i];
	return (ret);
}
