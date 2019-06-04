/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 21:04:26 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/27 21:04:29 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *ft_move(char *av, int way)
{
    int i;
    
    i = 0;
    while (1)
    {
        if (*av == '[')
            i++;
        else if (*av == ']')
            i--;
        if (!i)
            return (av);
        av += way;
    }
    return (NULL);
}

int main(int argc, char **argv)
{
    int    i;
    char   *ch;

    if (argc > 1)
    {
        ch = (char*)malloc(sizeof(char)*4096);
        i = 0;
        while (*argv[1])
        {
            if (*argv[1] == '>')
                i++;
            else if (*argv[1] == '<')
                i--;
            else if (*argv[1] == '+')
                ch[i]++;
            else if (*argv[1] == '-')
                ch[i]--;
            else if (*argv[1] == '.')
                write(1, &ch[i], 1);
            else if (*argv[1] == '[' && !ch[i])
                argv[1] = ft_move(argv[1], 1);
            else if (*argv[1] == ']' && ch[i])
                argv[1] = ft_move(argv[1], -1);
            argv[1]++;
        }
        free(ch);
    }
    else
        write(1, "\n", 1);
    return (0);
}