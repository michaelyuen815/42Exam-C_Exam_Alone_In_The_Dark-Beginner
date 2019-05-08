/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:02:11 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/03 19:08:53 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BL_SPACE(ch) (ch == 32 || ch == 9 || ch == 10)

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1] && BL_SPACE(*argv[1]))
			argv[1]++;
		while (*argv[1] && !BL_SPACE(*argv[1]))
			write(1, argv[1]++, 1);
	}
	write(1, "\n", 1);
	return (0);
}
