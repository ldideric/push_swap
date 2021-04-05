/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex_rra.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 13:49:06 by ldideric      #+#    #+#                 */
/*   Updated: 2021/04/05 12:59:14 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ex_rra(t_check *c)
{
	int	i;
	int	tmp;

	i = c->len - 1;
	if (c->a_[0] == 0)
		return ;
	while (i > 0 && c->a_[i] == 0)
		i--;
	tmp = c->a[i];
	if (i + 1 == c->len)
		i--;
	while (i >= 0)
	{
		if (c->a_[i + 1] == 1)
			c->a[i + 1] = c->a[i];
		i--;
	}
	c->a[i + 1] = tmp;
}
