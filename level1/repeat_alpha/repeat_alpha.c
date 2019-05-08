/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:08:11 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/06 14:15:01 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#define BL_UP(ch) (ch > 96 && ch < 123)
#define BL_LW(ch) (ch > 64 && ch < 91)

void	ft_print(char ch)
{
	size_t i;

	i = (BL_UP(ch) ? ch - 96 : ch - 64);
	while (i--)
		write(1, &ch , 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			if (BL_UP(*argv[1]) || BL_LW(*argv[1]))
				ft_print(*argv[1]);
			else
				write(1, argv[1], 1);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
