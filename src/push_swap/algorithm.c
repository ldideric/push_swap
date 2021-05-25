/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/27 17:16:25 by ldideric      #+#    #+#                 */
/*   Updated: 2021/05/25 17:34:25 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	init_push(t_data *d, t_check *c)
{
	int	i;

	i = 0;
	d->mid = 0;
	d->mid_i = 0;
	d->mid_step = 0;
	d->fixed = malloc(sizeof(int) * c->len);
	if (d->fixed == NULL)
		return (err_print("Error\n"));
	while (i < c->len)
	{
		d->fixed[i] = c->a[i];
		i++;
	}
	return (1);
}

void	use_func(char *func, t_check *c)
{
	ft_printf("%s", func);
	specifier(line_to_int(func), c);
}

void	find_mid(t_data *d, t_check *c)
{
	if (d->mid_step == 0)
	{
		d->mid_step = c->len / 2;
		d->mid_i = d->mid_step;
	}
	else
	{
		d->mid_step = d->mid_step / 2;
		if (d->mid_i % 2 == 0)
			d->mid_i = d->mid_i + d->mid_step;
		else
			d->mid_i = d->mid_i + d->mid_step + 1;
	}
	d->mid_i--;
	d->mid = d->fixed[d->mid_i];
}

void	quick_sort(t_data *d, t_check *c)
{
	int	i;

	i = 0;
	while (sorted(c) == 0)
	{
		find_mid(d, c);
		while (c->a_[d->mid_i + 2] != '1')
		{
			if (c->a[i] < d->mid)
				use_func("pb\n", c); // fix infinite loop
			use_func("ra\n", c);
		}
	}
}

void	sort_list(t_data *d, t_check *c)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < c->len)
	{
		key = d->fixed[i];
		j = i - 1;
		while (j >= 0 && d->fixed[j] > key)
		{
			d->fixed[j + 1] = d->fixed[j];
			j = j - 1;
		}
		d->fixed[j + 1] = key;
		i++;
	}
}

void	algorithm(t_check *check)
{
	t_data		data;
	int			i;

	i = 0;
	if (init_push(&data, check) == 0)
		return ;
	sort_list(&data, check);
	quick_sort(&data, check);
}
