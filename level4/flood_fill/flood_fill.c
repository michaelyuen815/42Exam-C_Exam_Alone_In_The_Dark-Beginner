/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:08:41 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/04 20:02:28 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

void	flood_fill(char **tab, t_point size, t_point begin)
{
	int i;
	int j;

	begin.y--;
	begin.x--;

	if (tab[begin.y][begin.x] == '1')
		return ;
	if (begin.y < 0 || begin.y >= size.y)
		return ;
	if (begin.x < 0 || begin.x >= size.x)
		return ;
	tab[begin.y][begin.x] = 'F';
	j = begin.x + 1;
	while (--j >= 0)
	{
		i = begin.y + 1;
		while (--i >= 0)
		{
			if (i != size.y - 1)
				if (tab[i + 1][j] == 'F' && tab[i][j] == '0')
					tab[i][j] = 'F';
			if (j != size.x - 1)
				if (tab[i][j + 1] == 'F' && tab[i][j] == '0')
					tab[i][j] = 'F';
		}
	}
	j = -1;
	while (++j < size.x)
	{
		i = -1;
		while (++i < size.y)
		{
			if (i)
				if (tab[i - 1][j] == 'F' && tab[i][j] == '0')
					tab[i][j] = 'F';
			if (j)
				if (tab[i][j - 1] == 'F' && tab[i][j] == '0')
					tab[i][j] = 'F';
		}
	}
}
