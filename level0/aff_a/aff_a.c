/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 09:01:40 by exam              #+#    #+#             */
/*   Updated: 2019/05/14 09:08:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1] != 'a' && *argv[1])
			argv[1]++;
		if (*argv[1])
			write(1, argv[1], 1);
		write(1, "\n", 1);
	}
	else
		write(1, "a\n", 2);
	return (0);
}