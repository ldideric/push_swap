/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex_ra.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 13:47:33 by ldideric      #+#    #+#                 */
/*   Updated: 2021/04/05 12:51:36 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ex_ra(t_check *c)
{
	int	tmp;
	int	i;

	i = 1;
	if (c->a_[1] == 0)
		return ;
	tmp = c->a[0];
	while (i != c->len && c->a_[i] == 1)
	{
		c->a[i - 1] = c->a[i];
		i++;
	}
	c->a[i - 1] = tmp;
}
