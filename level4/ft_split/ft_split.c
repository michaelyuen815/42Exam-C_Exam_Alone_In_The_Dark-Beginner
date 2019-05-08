/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:39:46 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/06 11:59:24 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define BL_SPACE(ch) (ch == 32 || ch == 9 || ch == 10)

size_t ft_wordlen(const char *str)
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

size_t ft_wcount(const char *str)
{
	size_t len;

	len = 1;
	while (*str)
	{
		if (BL_SPACE(*str))
		{
			while (BL_SPACE(*str))
				str++;
			len += (*str ? 1 : 0);
		}
		if (*str)
			str++;
	}
	return (len);
}
char *ft_strdup(char *str, size_t len)
{
	size_t	i;
	char	*ret;

	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = 0;
	i = -1;
	while (++i < len)
		ret[i] = str[i];
	return (ret);
}

char **ft_split(char *str)
{
	size_t	i;
	size_t	len;
	char	**ret;

	while (BL_SPACE(*str))
		str++;
	len = (*str ? ft_wcount(str) : 0);

	if (!(ret = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	ret[len] = NULL;
	i = -1;
	while (++i < len)
	{
		ret[i] = ft_strdup(str, ft_wordlen(str));
		str += ft_wordlen(str);
		while (BL_SPACE(*str))
			str++;
	}
	return (ret);
}
