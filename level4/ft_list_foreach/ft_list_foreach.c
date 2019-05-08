/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 21:18:01 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/06 21:46:09 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (!begin_list || !f)
		return;
	while (begin_list)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}
