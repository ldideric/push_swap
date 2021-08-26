/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/27 17:16:25 by ldideric      #+#    #+#                 */
/*   Updated: 2021/08/26 17:38:15 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	use_func(char *func, t_check *c)
{
	ft_printf("%s", func);
	specifier(line_to_int(func), c);
	print_arr(c);
}

int	init_push(t_data *d, t_check *c)
{
	int	i;

	i = 0;
	d->i = c->len - 1;
	d->less = 0;
	d->less_i = 0;
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
