/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex_pb.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 13:48:51 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/27 17:01:33 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ex_pb(t_check *c)
{
	int	i;

	if (c->a_[0] == 0)
		return ;
	ex_push_down(c, &c->b_, 'b');
	c->b[0] = c->a[0];
	i = 0;
	while (c->a_[i + 1] == 1)
	{
		c->a[i] = c->a[i + 1];
		i++;
	}
	c->a[i] = 0;
	c->a_[i] = 0;
	i = 0;
	while (c->b_[i] == 1)
		i++;
	c->b_[i] = 1;
}
