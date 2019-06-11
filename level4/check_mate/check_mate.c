/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:14:54 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/20 19:13:46 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"
#include <stdio.h>

int ft_check_chess(char *chess, char pt)
{
	while (*chess)
		if (*chess++ == pt)
			return (1);
	return (0);
}

int ft_check_line(char **board, t_point *king, t_point *chk, int ac, char *chess)
{
	int k;

	k = 1;
	while (king->i + chk->i * k >= 0 && \
			king->j + chk->j * k >= 0 && \
			king->i + chk->i * k < ac - 1 && \
			king->j + chk->j * k < ac - 1)
	{
		if (ft_check_chess(chess, board[king->i + chk->i * k][king->j + chk->j * k]))
			return (1);
		if (board[king->i + chk->i * k][king->j + chk->j * k] == 'P' && k == 1 && chk->i == 1 && chk->j)
			return (1);
		if (ft_check_chess(CHESSALL, board[king->i + chk->i * k][king->j + chk->j * k]))
			return (0);
		k++;
	}
	return (0);
}

int ft_check_main(int argc, char **board)
{
	t_point *king;
	t_point *t_chk;
	char	check;

	king = malloc(sizeof(t_point));
	king->i = -1;
	while (++(king->i) < argc - 1)
	{
		king->j = -1;
		while (board[king->i][++(king->j)])
			if (board[king->i][king->j] == 'K')
				break;
		if (board[king->i][king->j] == 'K')
			break;
	}
	if (king->i == argc - 1)
		return (0);
	check = 0;
	t_chk = malloc(sizeof(t_point));
	t_chk->i = -1;
	while (t_chk->i < 2)
	{
		t_chk->j= -1;
		while (t_chk->j < 2)
		{
			check |= ft_check_line(board, king, t_chk, argc, (t_chk->i && t_chk->j ? "BQ" : "RQ"));
			if (check)
				return (check);
			t_chk->j++;
		}
		t_chk->i++;
	}
	return (check);
}
