/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:25:59 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/06 11:32:13 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BL_SPACE(ch) (ch == 32 || ch == 9 || ch == 10)

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (BL_SPACE(*argv[1]))
			argv[1]++;
		if (*argv[1])
			write(1, argv[1]++, 1);
		while (*argv[1])
		{
			if BL_SPACE(*argv[1])
			{
				while (BL_SPACE(*argv[1]))
					argv[1]++;
				if (*argv[1])
					write(1, " ", 1);
			}
			if (*argv[1])
				write(1, argv[1]++, 1);
		}
	}
	write (1, "\n", 1);
	return (0);
}
