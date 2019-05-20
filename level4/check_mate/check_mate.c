/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:47:19 by exam              #+#    #+#             */
/*   Updated: 2019/05/14 12:45:39 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int ft_check_pawn(char **board, int i, int j)
{
	int ind;

	ind = 0;
	if (i && j)
		ind = board[i - 1][j - 1] == 'K';
	if (i && board[i - 1][j + 1])
		ind = ind || (board[i - 1][j + 1] == 'K');
	return (ind);
}

int ft_check_bisp(char **board, int i, int j, int len)
{
	int chk_i;

	chk_i = 0;
	while (++chk_i < len)
	{
		if (i - chk_i > -1 && j - chk_i < -1)
			if (board[i - chk_i][j - chk_i] == 'K')
				return (1);
		if (i + chk_i < len && j - chk_i < -1)
			if (board[i + chk_i][j - chk_i] == 'K')
				return (1);
		if (i - chk_i > -1 && j + chk_i < len)
			if (board[i - chk_i][j + chk_i] == 'K')
				return (1);
		if (i + chk_i < len && j + chk_i < len)
			if (board[i + chk_i][j + chk_i] == 'K')
				return (1);
	}
	return (0);
}

int ft_check_rook(char **board, int i, int j, int len)
{
	int chk_i;

	chk_i = 0;
	while (++chk_i < len)
	{
		if (i - chk_i > -1)
			if (board[i - chk_i][j] == 'K')
				return (1);
		if (i + chk_i < len)
			if (board[i + chk_i][j] == 'K')
				return (1);
		if (j - chk_i > -1)
			if (board[i][j - chk_i] == 'K')
				return (1);
		if (j + chk_i < len)
			if (board[i][j + chk_i] == 'K')
				return (1);
	}
	return (0);
}

int ft_check_mate(char **board, int len)
{
	int i;
	int j;
	int		BL_K;

	BL_K = 0;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (board[i][j] == 'P')
				if (ft_check_pawn(board, i, j))
					return (1);
			if (board[i][j] == 'B')
				if (ft_check_bisp(board, i, j, len))
					return (1);
			if (board[i][j] == 'R')
				if (ft_check_rook(board, i, j, len))
					return (1);
			if (board[i][j] == 'Q')
				if (ft_check_rook(board, i, j, len) || ft_check_bisp(board, i, j, len))
					return (1);
			if (board[i][j] == 'K')
				BL_K = 1;	
		}
	}
	if (BL_K)
		return (0);
	else
		return (1);
}
