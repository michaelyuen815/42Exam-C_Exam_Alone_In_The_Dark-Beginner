/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:12:37 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/20 19:04:53 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

char **ft_board(int argc, char **argv)
{
	int		i;
	int		j;
	char	**board;

	if (argc < 2 || argc > 9)
		return (NULL);
	if (!(board = (char**)malloc(sizeof(char*) * argc)))
		return (NULL);
	i = -1;
	board[argc - 1] = 0;
	while (++i < argc - 1)
	{
		j = -1;
		board[i] = (char*)malloc(sizeof(char) * argc);
		board[argc - 1] = 0;
		while (++j < argc - 1)
			board[i][j] = *argv[i + 1]++;
	}
	return (board);
}

int main(int argc, char **argv)
{
	char **board;

	if (argc > 1)
	{
		board = ft_board(argc, argv);
		if (ft_check_main(argc, board))
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
		free(board);
	}
	write(1, "\n", 1);
	return (0);
}
