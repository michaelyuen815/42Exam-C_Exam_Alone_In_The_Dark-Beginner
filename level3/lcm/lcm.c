/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:41:45 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/19 17:45:18 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int lcm(unsigned int a, unsigned int b)
{
	int base;
	int ret;

	if (a < 1 || b < 1)
		return (0);
	base = (a > b ? a : b);
	ret = base;

	while (ret % b || ret % a)
	   ret += base;
	return (ret);	
}
