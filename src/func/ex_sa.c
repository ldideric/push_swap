/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex_sa.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 13:49:15 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/22 14:29:18 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	ex_sa(t_check *c)
{
	int	tmp;

	tmp = c->a[0];
	c->a[0] = c->a[1];
	c->a[1] = tmp;
}
