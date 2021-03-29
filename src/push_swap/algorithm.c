/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/27 17:16:25 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/27 17:48:31 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	init_push(t_data *d, t_check *c)
{
	int	i;

	i = 0;
	d->max_commands = c->len + 5;
	d->tries = 0;
	d->short_list = malloc(sizeof(char *) * c->len);
	if (d->short_list == NULL)
		return (err_print("Error\n"));
	while (i < c->len)
	{
		d->short_list[i] = malloc(sizeof(char) * 4);
		if (d->short_list == NULL)
			return (err_print("Error\n"));
		i++;
	}
	return (1);
}

void	algorithm(t_check *check)
{
	t_data	data;
	int		iter[data.max_commands];
	int		i;

	i = 0;
	while (i < data.max_commands)
	{
		iter[i] = 0;
		i++;
	}
	if (init_push(&data, check) == 0)
		return ;
	while (iter[0] < 11)
	{
		iter[0]++;
	}
}
