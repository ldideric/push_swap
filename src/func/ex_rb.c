/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex_rb.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 13:48:56 by ldideric      #+#    #+#                 */
/*   Updated: 2021/04/05 12:51:59 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ex_rb(t_check *c)
{
	int	tmp;
	int	i;

	i = 1;
	if (c->b_[1] == 0)
		return ;
	tmp = c->b[0];
	while (i != c->len && c->b_[i] == 1)
	{
		c->b[i - 1] = c->b[i];
		i++;
	}
	c->b[i - 1] = tmp;
}
