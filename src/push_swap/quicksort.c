/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 16:55:21 by ldideric      #+#    #+#                 */
/*   Updated: 2021/08/26 19:17:40 by ldideric      ########   odam.nl         */
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

int	is_two_away(t_data *d, t_check *c, int a)
{
	if (a == 0)
	{
		if (d->fixed[d->i] == c->b[0]
			|| d->fixed[d->i] == c->b[1])
			return (1);
	}
	else
		if (d->fixed[d->i] == c->a[0]
			|| d->fixed[d->i] == c->a[1])
			return (1);
	return (0);
}

void	splitter(t_data *d, t_check *c)
{
	while (c->a_[0] != 0)
	{
		find_mid_split(d, c, 0);
		while (c->a_[d->less_i + 1] == 1)
		{
			if (c->a[0] <= d->less)
				use_func("pb\n", c);
			else
				use_func("ra\n", c);
		}
	}
	while (is_two_away(d, c, 0) == 1)
	{
		if (d->fixed[d->i] == c->b[0])
		{
			use_func("pa\n", c);
			d->i--;
		}
		else
			use_func("sb\n", c);
	}
	d->mid_step = 0;
	find_mid_split(d, c, 0);
}

void	splitter2(t_data *d, t_check *c)
{
	while (c->b_[0] != 0)
	{
		find_mid_split(d, c, 1);
		while (c->b_[d->less_i + 1] == 1)
		{
			if (c->b[0] >= d->less)
				use_func("pa\n", c);
			else
				use_func("rb\n", c);
		}
	}
	d->i = 0;
	while (is_two_away(d, c, 1) == 1)
	{
		if (d->fixed[d->i] == c->a[0])
		{
			use_func("pb\n", c);
			d->i++;
		}
		else
			use_func("sa\n", c);
	}
}

void	quick_sort(t_data *d, t_check *c)
{
	while (sorted(c) == 0)
	{
		splitter(d, c);
		while (c->b[0] > d->less)
			use_func("pa\n", c);
		splitter2(d, c);
		sort_mid(d, c);
	}
}
