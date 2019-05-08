/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:25:16 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/06 10:32:29 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int		sign;
	size_t	len;
	size_t	i;
	char	*ret;
	char	tab[13];

	len = 0;
	sign = (nbr < 0 ? -1 : 1);
	if (!nbr)
		tab[len++] = '0';
	while (nbr)
	{
		tab[len++] = nbr % 10 * sign + '0';
		nbr /= 10;
	}
	if (sign == -1)
		tab[len++] = '-';
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	tab[len] = 0;
	while (++i < len)
		ret[i] = tab[len - i - 1];
	return (ret);
}
