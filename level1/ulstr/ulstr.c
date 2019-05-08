/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:22:41 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/04 18:28:15 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define BL_LW(ch) (ch > 96 && ch < 123)
#define BL_UP(ch) (ch > 64 && ch < 91)

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			if (BL_LW(*argv[1]))
				ft_putchar(*argv[1] - 32);
			else if (BL_UP(*argv[1]))
				ft_putchar(*argv[1] + 32);
			else
				ft_putchar(*argv[1]);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
