/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:01:13 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/27 20:16:40 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BL_UP(ch) (ch > 64 && ch < 91)
#define BL_LW(ch) (ch > 96 && ch < 123)
#define BL_SP(ch) (ch == 32 || ch == 9)

void ft_putchar(char ch)
{
	write(1, &ch, 1);
}

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc > 1)
	{
		while (++i < argc)
		{
			while (*argv[i])
			{
				if (BL_UP(*argv[i]) && !BL_SP(*(argv[i] + 1)) && *(argv[i] + 1))
					ft_putchar(*argv[i]++ + 32);
				else if (BL_LW(*argv[i]) && (BL_SP(*(argv[i] + 1)) || !*(argv[i] + 1)))
					ft_putchar(*argv[i]++ - 32);
				else
					ft_putchar(*argv[i]++);
			}
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
