/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:09:35 by exam              #+#    #+#             */
/*   Updated: 2019/04/12 21:21:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int nbr;
	int i;
	
	nbr = 0;
	i = 1;
	if (argc == 2)
	{
		nbr = atoi(argv[1]);
		if (nbr > 1)
		{
			while (++i < nbr)
			{
				if (nbr % i == 0)
				{
					nbr /= i;
					printf("%d*", i--);
				}
			}
			printf("%d", i);
		}
		else if (nbr == 1)
			printf("%d", nbr);
	}
	printf("\n");
	return (0);
}
