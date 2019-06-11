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

int ft_check_main(int argc, char **board)
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i < argc - 1)
	{
		j = -1;
		while (board[i][++j])
			if (board[i][j] == 'K')
				break;
		if (board[i][j] == 'K')
			break;
	}
	if (i == argc - 1)
		return (0);
	k = 1;
	while (i - k >= 0 && j - k >= 0)
	{
		if (board[i - k][j - k] == 'B' || board[i - k][i - k] == 'Q')
			return (1);
		else if (board[i - k][j - k] == 'P' || board[i - k][j - k] == 'R')
			break;
		k++;
	}
	k = 1;
	while (i - k >= 0 && j + k < argc - 1)
	{
		if (board[i - k][j + k] == 'B' || board[i - k][i + k] == 'Q')
			return (1);
		else if (board[i - k][j + k] == 'P' || board[i - k][j + k] == 'R')
			break;
		k++;
	}
	k = 1;
	while (i - k >= 0)
	{
		if (board[i - k][j] == 'R' || board[i - k][j] == 'Q')
			return (1);
		else if (board[i - k][j] == 'B' || board[i - k][j] == 'P')
			break;
		k++;
	}
	k = 1;
	while (i + k < argc - 1)
	{
		if (board[i + k][j] == 'R' || board[i + k][j] == 'Q')
			return (1);
		else if (board[i + k][j] == 'B' || board[i + k][j] == 'P')
			break;
		k++;
	}
	k = 1;
	while (j - k >= 0)
	{
		if (board[i][j - k] == 'R' || board[i][j - k] == 'Q')
			return (1);
		else if (board[i][j - k] == 'B' || board[i][j - k] == 'P')
			break;
		k++;
	}
	k = 1;
	while (j + k < argc - 1)
	{
		if (board[i][j + k] == 'R' || board[i][j + k] == 'Q')
			return (1);
		else if (board[i][j + k] == 'B' || board[i][j - k] == 'P')
			break;
		k++;
	}
	k = 1;
	while (i + k < argc -1 && j - k >= 0)
	{
		if (board[i + k][j - k] == 'B' || board[i + k][j - k] == 'Q' || (k == 1 && board[i + k][j - k] == 'P'))
			return (1);
		else if (board[i + k][j - k] == 'R' || board[i + k][j - k] == 'P')
			break;
		k++;
	}
	k = 1;
	while (i + k < argc - 1 && j + k < argc - 1)
	{
		if (board[i + k][j + k] == 'B' || board[i + k][j + k] == 'Q' || (k == 1 && board[i + k][j + k] == 'P'))
			return (1);
		else if (board[i + k][j + k] == 'R' || board[i + k][j + k] == 'P')
			break;
		k++;
	}
	return (0);
}
