/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:18:10 by exam              #+#    #+#             */
/*   Updated: 2019/05/14 12:44:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"
#include <stdio.h>

char **ft_board(int ac, char **av)
{
	char **board;
	int	i;
	int	j;

	if (!(board = (char**)malloc(sizeof(char*) * ac)))
		return (NULL);
	board[ac - 1] = NULL;
	i = -1;
	while (++i < ac - 1)
	{
		j = -1;
		if (!(board[i] = (char*)malloc(sizeof(char) * ac)))
		{
			free(board);
			return (NULL);
		}
		board[i][ac - 1] = 0;
		while (++j < ac - 1 && *av[i + 1])
			board[i][j] = *av[i + 1]++;
		if (!(ac - 1 == j && !*av[i + 1]))
		{
			free(board);
			return (NULL);
		}
	}
	return (board);
}

int	main(int argc, char **argv)
{
	char **board;

	if (argc > 1)
	{
		board = ft_board(argc, argv);
		if (board)
		{
			if (ft_check_mate(board, argc - 1))
				write(1, "Success", 7);
			else
				write(1, "Fail", 4);
			free(board);
		}
		else
			write(1, "Fail", 4);
	}
	write(1, "\n", 1);
	return (0);
}
