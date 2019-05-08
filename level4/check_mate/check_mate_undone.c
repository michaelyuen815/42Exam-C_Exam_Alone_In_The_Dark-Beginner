/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:05:51 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/03 20:34:17 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_success(void)
{
	write(1, "Success\n", 8);
}

void ft_fail(void)
{
	write(1, "Fail\n", 5);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (*str++)
		len++;
	return (len);
}

int main(int agrc, char **argv)
{
	size_t	i;
	size_t	j;
	char	**chk;
	
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		chk = (char**)malloc(sizeof(char*) * agrc);
		i = -1;
		while (++i < argc)
		{
			chk[i] = (char*)malloc(sizeof(char) * argc);
			j = 0;
			while (argv[i][j])
			{
				j++;
			}
	}
	return (0);
}
