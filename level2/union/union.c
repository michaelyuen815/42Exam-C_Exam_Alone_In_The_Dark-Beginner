/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:18:46 by exam              #+#    #+#             */
/*   Updated: 2019/05/07 09:28:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int ch[256];

	i = 0;
	while (++i < 257)
		ch[i] = 0;

	if (argc == 3)
	{
		i = 0;
		while (++i < argc)
		{
			while (*argv[i])
			{
				if (!ch[(int)*argv[i]])
				{
					write(1, argv[i], 1);
					ch[(int)*argv[i]]++;
				}
				argv[i]++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
