/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 09:45:36 by exam              #+#    #+#             */
/*   Updated: 2019/05/14 10:19:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BL_SP(ch) (ch == 32 || ch == 9)
#define BL_NUM(ch) (ch > 47 && ch < 58)
#define CH_HEX "0123456789abcdef"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	nbr;
	int	hex;

	nbr = 0;
	if (argc == 2)
	{
		while (BL_SP(*argv[1]))
			argv[1]++;
		if (*argv[1] == '+')
			argv[1]++;
		if (BL_NUM(*argv[1]))
		{
			while (BL_NUM(*argv[1]))
				nbr = nbr * 10 + *argv[1]++ - '0';
			hex = 7;
			while (hex > 0 && !(nbr >> hex * 4))
				hex--;
			hex++;
			while (hex--)
				ft_putchar(CH_HEX[(nbr >> hex * 4) & 15]);
		}
	}
	write(1, "\n", 1);
	return (0);
}
