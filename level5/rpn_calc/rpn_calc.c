/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:16:33 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/04 21:35:41 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define OP(ch) (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
#define SP(ch) (ch == 9 || ch == 32 || ch == 10)
#define NUM(ch) (ch > 47 && ch < 58)

size_t ft_wcount(const char *str)
{
	size_t len;

	len = 1;
	while (*str)
	{
		if (SP(*str))
		{
			while (SP(*str))
				str++;
			if (*str)
				len++;
		}
		if (*str)
			str++;
	}
	return (len);
}

void	ft_nextsp(char **str)
{
	while (**str && !SP(**str))
		(*str)++;
	while (SP(**str))
		(*str)++;
}

void rpn_calc(char *str)
{
	size_t i;
	int *tab;

	i = 0;
	tab = (int*)malloc(sizeof(int) * ft_wcount(str));
	while (SP(*str))
		str++;
	while (*str)
	{
		if (NUM(*str) || (*str == '-' && NUM(*str)))
			tab[i++] = atoi(str);
		else if (OP(*str))
		{
			if (i < 2)
			{
				printf("Error\n");
				return;
			}
			else
			{
				if (*str == '+')
					tab[i - 2] = tab[i - 2] + tab[i - 1];
				if (*str == '-')
					tab[i - 2] = tab[i - 2] - tab[i - 1];
				if (*str == '*')
					tab[i - 2] = tab[i - 2] * tab[i - 1];
				if (*str == '/')
					tab[i - 2] = tab[i - 2] / tab[i - 1];
				if (*str == '%')
					tab[i - 2] = tab[i - 2] % tab[i - 1];
				i--;
			}
		}
		else
		{
			i = 0;
			break;
		}
		ft_nextsp(&str);
	}
	if (i != 1)
		printf("Error\n");
	else
		printf("%d\n", tab[0]);
	free(tab);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		printf("Error\n");
	else if (!*argv[1])
		printf("Error\n");
	else
		rpn_calc(argv[1]);
	return (0);
}
