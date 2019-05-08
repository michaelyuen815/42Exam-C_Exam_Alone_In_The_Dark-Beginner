/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 10:03:39 by exam              #+#    #+#             */
/*   Updated: 2019/04/19 10:11:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	maff_revalpha(void)
{
	char ch;
	char tmp;

	ch = 'z';

	while (ch >= 'a')
	{
		tmp = ch - 32;
		if (ch % 2)
			write(1, &tmp, 1);
		else
			write(1, &ch, 1);
		--ch;
	}
	write(1, "\n", 1);
}

int		main(void)
{
	maff_revalpha();
	return (0);
}
