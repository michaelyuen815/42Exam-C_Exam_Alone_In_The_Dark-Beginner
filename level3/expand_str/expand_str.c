/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:44:43 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/04 19:01:17 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BL_SPACE(ch) (ch == 32 || ch == 9)

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (BL_SPACE(*argv[1]))
			argv[1]++;
		while (*argv[1])
		{
			if (BL_SPACE(*argv[1]))
			{
				while (BL_SPACE(*argv[1]))
					argv[1]++;
				if (*argv[1])
					write(1, "   ", 3);
			}
			if (*argv[1])
				write(1, argv[1]++, 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
