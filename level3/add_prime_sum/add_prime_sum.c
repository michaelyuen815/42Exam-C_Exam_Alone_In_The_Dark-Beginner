/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:07:34 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/13 20:29:09 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_isprime(int nbr)
{
	int i;

	i = 2;
	if (nbr < 2)
		return (0);
	if (nbr == 2)
		return (1);
	while (nbr % i && i * i <= nbr)
		i++;
	return (nbr % i);
}

int ft_atoi(char *str)
{
	int ret;

	ret = 0;
	while(*str == ' ' || *str == '\t')
		str++;
	if (*str == '+')
		str++;
	while (*str > 47 && *str < 58)
		ret = ret * 10 + *str++ - '0';
	return (ret);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int tol)
{
	if (tol >= 10)
		ft_putnbr(tol / 10);
	ft_putchar(tol % 10 + '0');
}

int main(int argc, char **argv)
{
	int nbr;
	int ret;

	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		ret = 0;
		while (nbr > 1)
		{
			ret = ret + (ft_isprime(nbr) ? nbr : 0);
			nbr--;
		}
		ft_putnbr(ret);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
