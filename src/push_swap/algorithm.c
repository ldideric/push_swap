/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/27 17:16:25 by ldideric      #+#    #+#                 */
/*   Updated: 2021/04/19 14:08:57 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	init_push(t_data *d, t_check *c)
{
	int	i;

	i = 0;
	d->i = -1;
	d->tries = 0;
	d->short_len = 0;
	d->work_tries = 0;
	d->max_commands = c->len + 5;
	d->combinations = power(11, d->max_commands);
	d->short_list = malloc(sizeof(char *) * (d->max_commands + 1));
	d->temp = malloc(sizeof(char) * (d->max_commands + 1));
	if (d->short_list == NULL || d->temp == NULL)
		return (err_print("Error\n"));
	while (i < d->max_commands + 1)
	{
		d->temp[i] = '0';
		d->short_list[i] = malloc(sizeof(char) * 5);
		if (d->short_list[i] == NULL)
			return (err_print("Error\n"));
		d->short_list[i][0] = '0';
		i++;
	}
	return (1);
}

void	merge_sort(t_data *d, t_check *c)
{
	if (sorted(c) == 1)
		return ;
	//split in two, then merge sort
}

void	algorithm(t_check *check)
{
	t_data		data;
	int			i;

	i = 0;
	if (init_push(&data, check) == 0)
		return ;
	merge_sort(&data, check);
	printf("%'lld tries done\n%'d functioning combinations\n", data.tries, data.work_tries);
	printf("shortest try of %d command(s):\n", data.short_len);
	while (data.short_list[i][0] != '0')
	{
		printf("%s", data.short_list[i]);
		i++;
	}
}
