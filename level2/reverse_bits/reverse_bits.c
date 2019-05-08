/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:16:47 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/06 14:38:34 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	size_t i;
	unsigned char ret;

	i = 0;
	ret = 0;

	while (i < 8)	
		ret = (ret << 1 | (1 & octet >> i++));
	return (ret);
}
