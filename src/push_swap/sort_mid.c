/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_mid.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 17:48:54 by ldideric      #+#    #+#                 */
/*   Updated: 2021/08/26 20:01:12 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	find_mid_split(t_data *d, t_check *c, int a)
{
	if (d->mid_step == 0)
	{
		d->mid_step = c->len / 2;
		d->less_i = d->mid_step - 1;
		d->less = d->fixed[d->less_i];
	}
	else
	{
		d->mid_step = d->mid_step / 2;
		if (d->mid_step == 0)
			d->mid_step++;
		if (a == 0)
			d->less = d->less + d->mid_step;
		else
			d->less = d->less - d->mid_step;
		d->less_i = d->less_i - d->mid_step;
	}
}

void	search_sort(t_data *d, t_check *c)
{}

void	sort_mid(t_data *d, t_check *c)
{
	d->s_start = c->b[0];
	while (c->b_[0] != 0)
		use_func("pa\n", c);
	while (c->a[0] != d->s_start)
		use_func("ra\n", c);
	use_func("ra\n", c); // hier bezig
	d->mid_step = 0;
	find_mid_split(d, c, 0)
	while (c->a[0] < c->len / 2)
	{
		if (c->a[0] < c->len / 4)
			use_func("pb\n", c);
		else
			use_func("ra\n", c);
	}
	search_sort(d, c);
}
