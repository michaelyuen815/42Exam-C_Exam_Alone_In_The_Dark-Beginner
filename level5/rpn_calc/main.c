/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:18:16 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/20 19:55:44 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define BL_SP(ch) (ch == 32 || ch == 9)
#define BL_OP(ch) (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')

size_t ft_count(char *argv)
{
	size_t len;
	
	len = 1;
	while (*argv++)
		if (BL_SP(*(argv - 1)) && *argv)
			len++;
	return (len);
}

char *ft_next(char *argv)
{
	while (*argv && !BL_SP(*argv))
		argv++;
	while (BL_SP(*argv))
		argv++;
	return (argv);
}

int ft_rpn_signcal(int prev, int cur, char op)
{
	if (op == '+')
		return (prev + cur);
	if (op == '-')
		return (prev - cur);
	if (op == '*')
		return (prev * cur);
	if (op == '/')
		return (prev / cur);
	if (op == '%')
		return (prev % cur);
	else
		return (0);
}

int ft_rpn_calc(char *argv)
{
	size_t i;
	size_t len;
	int *tab;

	while (BL_SP(*argv))
		argv++;
	len = (*argv ? ft_count(argv) : 0);
	tab = (int*)malloc(sizeof(int) * len);
	i = 0;
	while (*argv)
	{
		if (atoi(argv) || *argv == '0')
			tab[i++] = atoi(argv);
		else if (BL_OP(*argv))
		{
			if (i < 2)
                break;
			if ((*argv == '/' || *argv == '%') && tab[i - 1] == 0)
                break;
			tab[i - 2] = ft_rpn_signcal(tab[i - 2], tab[i - 1], *argv);
			--i;
		}
		else
            break;
		argv = ft_next(argv);
	}
	if (i != 1 || *argv)
	{
		free(tab);
		return (0);
	}
	printf("%d\n", tab[0]);
	free(tab);
	return (1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_rpn_calc(argv[1]))
			printf("Error\n");
	}
	else
		printf("Error\n");
	return (0);
}
