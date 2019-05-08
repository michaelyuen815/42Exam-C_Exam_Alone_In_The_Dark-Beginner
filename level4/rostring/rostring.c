/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:09:03 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/06 15:51:01 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define BL_SPACE(ch) (ch == 32 || ch == 9)

char	*ft_skipsp(const char *str)
{
	while (BL_SPACE(*str))
		str++;
	return ((char*)str);
}

size_t	ft_wordcount(const char *str)
{
	size_t len;

	len = 0;
	while (*str && !BL_SPACE(*str))
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_firstword(char **str)
{
	size_t	i;
	size_t	len;
	char	*ret;

	*str = ft_skipsp(*str);
	len = (**str ? ft_wordcount(*str) : 0);
	if (!len)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(char) * (1 + len))))
		return (NULL);
	ret[len] = 0;
	i = -1;
	while (++i < len)
		ret[i] = *(*str)++;
	*str = ft_skipsp(argv[1])
	return (ret);
}

int		main(int argc, char **argv)
{
	size_t	i;
	char	*str_word;

	if (argc > 1)
	{
		str_word = ft_firstword(&argv[1]);
		i = 0;
		while (*argv[1])
		{
			if (BL_SPACE(*argv[1]))
			{
				argv[1] = ft_skipsp(argv[1]);
				if (*argv[1])
					write(1, " ", 1);
			}
			if (*argv[1])
			{
				i = 1;
				write(1, argv[1]++, 1);
			}
		}
		if (str_word)
		{
			if (i)
				write(1, " ", 1);
			i = 0;
			while (str_word[i])
				write(1, &str_word[i++], 1);
			free(str_word);
		}
	}
	write(1, "\n", 1);
	return (0);
}
