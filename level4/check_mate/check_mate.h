/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:18:39 by exam              #+#    #+#             */
/*   Updated: 2019/05/14 12:18:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MATE_H
# define CHECK_MATE_H

# include <stdlib.h>
# include <unistd.h>

# define CHESSALL "BQPRK"

typedef struct 	s_point
{
	int i;
	int j;
}		t_point;

int ft_check_main(int argc, char **board);

#endif
