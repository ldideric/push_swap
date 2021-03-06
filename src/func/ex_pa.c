/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex_pa.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 13:48:39 by ldideric      #+#    #+#                 */
/*   Updated: 2021/04/05 12:51:18 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ex_pa(t_check *c)
{
	int	i;

	if (c->b_[0] == 0)
		return ;
	ex_push_down(c, &c->a_, 'a');
	c->a[0] = c->b[0];
	i = 0;
	while (i + 1 != c->len && c->b_[i + 1] == 1)
	{
		c->b[i] = c->b[i + 1];
		i++;
	}
	c->b[i] = 0;
	c->b_[i] = 0;
	i = 0;
	while (c->a_[i] == 1)
		i++;
	c->a_[i] = 1;
}
