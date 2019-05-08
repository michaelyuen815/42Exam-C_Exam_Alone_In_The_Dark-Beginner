/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:17:33 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/03 19:48:28 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BL_UPPER(ch) (ch > 64 && ch < 91)
#define BL_LOWER(ch) (ch > 96 && ch < 123)
#define BL_SP(ch) (ch == 32 || ch == 9)

int main(int argc, char **argv)
{
	int		i;
	char	tmp;

	i = 0;
	if (argc > 1)
	{
		while (++i < argc)
		{
			if (*argv[i])
			{
				tmp = *argv[i] - (BL_LOWER(*argv[i]) ? 32 : 0);
				write(1, &tmp, 1);
				argv[i]++;
			}
			while (*argv[i])
			{
				if (BL_SP(*(argv[i] - 1)) && BL_LOWER(*argv[i]))
					tmp = *argv[i] - 32;
				else if (!BL_SP(*(argv[i] - 1)) && BL_UPPER(*argv[i]))
					tmp = *argv[i] + 32;
				else
					tmp = *argv[i];
				write(1, &tmp, 1);
				argv[i]++;
			}
			write (1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
