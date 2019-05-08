/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:52:31 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/06 16:04:49 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define OCTET "0123456789abcdef"

void ft_printoctet(unsigned char ch)
{
	write(1, &OCTET[ch / 16], 1);
	write(1, &OCTET[ch % 16], 1);
}

void ft_printch(unsigned char ch)
{
	if (ch > 31 && ch < 127)
		write(1, &ch, 1);
	else
		write(1, ".", 1);
}

void print_memory(const void *addr, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned char	*tab;

	i = -1;
	tab = (unsigned char*)addr;
	while (++i < size)
	{
		ft_printoctet(tab[i]);
		if (i % 2)
			write(1, " ", 1);
		if (i % 16 == 15 || i == size - 1)
		{
			if (i == size - 1)
			{
				j = 2.5 * (15 - i % 16) + (!(i % 2) ? 1 : 0);
				while (j--)
					write(1, " ", 1);
			}
			j = -1;
			while (++j <= i % 16)
				ft_printch(tab[i / 16 * 16 + j]);
			write(1, "\n", 1);
		}
	}
}
