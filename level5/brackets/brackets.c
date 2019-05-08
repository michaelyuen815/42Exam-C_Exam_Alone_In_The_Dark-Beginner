/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 21:52:48 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/06 22:19:22 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_process(char *str)
{
	size_t j;
	char tmp[4096];

	j = 0;
	while (*str)
	{
		if (*str == '(' || *str == '[' || *str == '{')
			tmp[j++] = *str;
		else if (*str == ')' || *str == ']' || *str == '}')
		{
			if (!j)
				return (0);
			if ((*str == ')' && tmp[j - 1] == '(') || \
				(*str == ']' && tmp[j - 1] == '[') || \
				(*str == '}' && tmp[j - 1] == '{'))
				tmp[--j] = 0;
			else
				return (0);
		}
		str++;
	}
	if (!j)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		while (++i < argc)
		{
			if (ft_process(argv[i]))
				write (1, "OK\n", 3);
			else
				write (1, "Error\n", 6);
		}
	}
	return (0);
}
