/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 09:32:31 by exam              #+#    #+#             */
/*   Updated: 2019/05/14 09:44:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BL_UP(ch) (ch > 64 && ch < 91)
#define BL_LW(ch) (ch > 96 && ch < 123)

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			if (BL_UP(*argv[1]))
				ft_putchar('N' + 'M' - *argv[1]);
			else if (BL_LW(*argv[1]))
				ft_putchar('n' + 'm' - *argv[1]);
			else
				write(1, argv[1], 1);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
