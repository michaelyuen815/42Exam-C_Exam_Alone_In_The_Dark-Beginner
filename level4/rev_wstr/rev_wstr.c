/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:50:11 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/20 14:45:58 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define BL_SP(ch) (ch == 32 || ch == 9)

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

size_t ft_wordcount(char *str)
{
	size_t len;
	len = 1;
	str++;
	while (*str)
	{
		if (BL_SP(*(str - 1)) && !BL_SP(*str))
			len++;
		str++;
	}
	return (len);
}

size_t	ft_lettercount(char *str)
{
	size_t len;
	len = 0;
	while (*str && !BL_SP(*str))
	{
		str++;
		len++;
	}
	return (len);
}

char *ft_strsub(char **str)
{
	size_t	i;
	size_t	len;
	char	*ret;

	len = ft_lettercount(*str);
	ret = (char*)malloc(sizeof(char) * (len + 1));
	ret[len] = 0;
	i = -1;
	while (++i < len)
		ret[i] = *(*str)++;
	return (ret);
}

int main(int argc, char **argv)
{
	int	i;
	int	len;
	char	**split;
	
	if (argc == 2)
	{
		len = (*argv[1] ? ft_wordcount(argv[1]) : 0);
		split = (char**)malloc(sizeof(char*) * (len + 1));
		split[len] = 0;
		i = -1;
		while (++i < len)
		{
			split[i] = ft_strsub(&argv[1]);
			if (argv[1])
				argv[1]++;
		}
		while (--i > 0)
		{
			ft_putstr(split[i]);
			write(1, " ", 1);
		}
		ft_putstr(split[0]);
	}
	write(1, "\n", 1);
	return (0);
}
