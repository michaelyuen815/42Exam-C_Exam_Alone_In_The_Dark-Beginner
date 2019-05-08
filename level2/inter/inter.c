/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:14:15 by exam              #+#    #+#             */
/*   Updated: 2019/04/30 09:57:36 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int stor[128];
	int t;

	t = 0;
	while (++t < 129)
		stor[t] = 0;
	if (argc == 3)
	{
		while (*argv[2])
		{
			stor[(int)*argv[2]]++;
			argv[2]++;
		}
		while (*argv[1])
		{
			if (stor[(int)*argv[1]])
			{
				write(1, argv[1], 1);
				stor[(int)*argv[1]] = 0;
			}
			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
