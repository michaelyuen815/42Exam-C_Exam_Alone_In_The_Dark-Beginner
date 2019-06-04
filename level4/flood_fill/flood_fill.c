/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:47:14 by exam              #+#    #+#             */
/*   Updated: 2019/05/14 11:13:30 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char ch;

	ch = tab[begin.x][begin.y];
	if (begin.y > size.y || begin.x > size.x || begin.x < 1 || begin.y < 1)
		return ;
	if (tab[begin.x][begin.y] == 'F')
		return ;
	tab[begin.x][begin.y] = 'F';
	if (begin.x != 1)
		if (tab[begin.x - 1][begin.y] == ch)
			flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
	if (begin.y != 1)
		if (tab[begin.x][begin.y - 1] == ch)
			flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
	if (begin.x != size.x)
		if (tab[begin.x + 1][begin.y] == ch)
			flood_fill(tab, size, (t_point){begin.x + 1, begin.y});	
	if (begin.y != size.y)
		if (tab[begin.x][begin.y + 1] == ch)
			flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
}
