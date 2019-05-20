/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:03:44 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/13 21:40:10 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define BL_SP(ch) (ch == 32)
#define BL_OP(ch) (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')

char *ft_next(char *str)
{
	while (!BL_SP(*str) && *str)
		str++;
	while (BL_SP(*str))
		str++;
	return (str);
}

size_t ft_strwlen(char *str)
{
	size_t len = 1;
	while (*str)
	{
		if (BL_SP(*str) && !(BL_SP(*(str + 1)) && *(str + 1)))
			len++;
		str++;
	}
	return (len);
}

int ft_cal(int pre, int cur, char op)
{
	if (op == '+')
		return (pre + cur);
	else if (op == '-')
		return (pre - cur);
	else if (op == '*')
		return (pre * cur);
	else if (op == '/')
		return (pre / cur);
	else if (op == '%')
		return (pre % cur);
	else
		return (0);
}

int main(int argc, char **argv)
{
	int i;
	int *cal;

	if (argc == 2)
	{
		i = 0;
		while (BL_SP(*argv[1]))
			argv[1]++;
		cal = malloc(sizeof(int) * ft_strwlen(argv[1]));
		while (*argv[1])
		{
			if (atoi(argv[1]) || *argv[1] == '0')
				cal[i++] = atoi(argv[1]);
			else if (BL_OP(*argv[1]))
			{
				if (i < 2)
					break;
				else if ((*argv[1] == '%' || *argv[1] == '/') && !cal[i - 1])
					break;
				else	
				{
					cal[i - 2] = ft_cal(cal[i - 2], cal[i - 1], *argv[1]);
					i--;
				}
			}
			else 
				break;
			argv[1] = ft_next(argv[1]);
		}
		if (*argv[1] || i != 1)
			printf("Error\n");
		else
			printf("%d\n", cal[0]);
		free(cal);
	}
	else
		printf("Error\n");
	return (0);
}

