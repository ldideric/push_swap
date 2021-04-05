/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex_rrb.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 13:49:09 by ldideric      #+#    #+#                 */
/*   Updated: 2021/04/05 12:59:46 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ex_rrb(t_check *c)
{
	int	i;
	int	tmp;

	i = c->len - 1;
	if (c->b_[0] == 0)
		return ;
	while (i > 0 && c->b_[i] == 0)
		i--;
	tmp = c->b[i];
	if (i + 1 == c->len)
		i--;
	while (i >= 0)
	{
		if (c->b_[i + 1] == 1)
			c->b[i + 1] = c->b[i];
		i--;
	}
	c->b[i + 1] = tmp;
}
