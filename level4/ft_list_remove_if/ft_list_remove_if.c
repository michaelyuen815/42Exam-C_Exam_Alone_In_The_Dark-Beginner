/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:11:39 by exam              #+#    #+#             */
/*   Updated: 2019/04/30 10:59:53 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *t_chk;
	t_list *tmp;

	if (*begin_list == NULL)
		return;
	t_chk = *begin_list;
	
	while (t_chk->next)
	{
		if (!cmp(data_ref, t_chk->next->data))
		{
			tmp = t_chk->next;
			t_chk->next = tmp->next;
			free(tmp);
		}
		else
			t_chk = t_chk->next;
	}
	if (!cmp(data_ref, (*begin_list)->data))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	} 
}
