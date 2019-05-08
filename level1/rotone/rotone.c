/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:09:56 by exam              #+#    #+#             */
/*   Updated: 2019/05/07 09:17:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			if ((*argv[1] > 64 && *argv[1] < 90) || \
					(*argv[1] > 96 && *argv[1] < 122))
				ft_putchar(*argv[1] + 1);
			else if (*argv[1] == 90 || *argv[1] == 122)
				ft_putchar(*argv[1] - 25);
			else
				ft_putchar(*argv[1]);
			argv[1]++;
		}
	}
	ft_putchar('\n');
	return (0);
}
