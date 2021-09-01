/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_mid.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:48:54 by ldideric      #+#    #+#                 */
/*   Updated: 2021/09/01 13:06:05 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// void	search_sort(t_data *d, t_check *c)
// {}

void	sort_mid(t_data *d, t_check *c)
{
	// d->s_start = c->b[0];
	// while (c->b_[0] != 0)
	// 	use_func("pa\n", c);
	// while (c->a[0] != d->s_start)
	// 	use_func("ra\n", c);
	// use_func("ra\n", c);
	d->mid_step = 0;
	find_mid_split(d, c, 0);
	while (c->a_[d->less_i + 1] == 1)
	{
		if (c->a[0] <= d->less)
			use_func("pb\n", c);
		else
			use_func("ra\n", c);
	}
	// search_sort(d, c);
}
