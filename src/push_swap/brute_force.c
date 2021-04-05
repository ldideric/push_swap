/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brute_force.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/05 15:55:52 by ldideric      #+#    #+#                 */
/*   Updated: 2021/04/05 15:57:24 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#include <stdio.h>
#include <locale.h>

int	init_push(t_data *d, t_check *c)
{
	int	i;

	setlocale(LC_NUMERIC, ""); //remove
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

void	try_option(t_data *d, t_check *c)
{
	static char	*list[11] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n",
		"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	t_check		c2;
	int			i;

	i = 0;
	d->tries++;
	if (d->tries % 10000000 == 0)
		printf("%'lld of %'lld estimate tries\n", d->tries, d->combinations);
	if (length_arr(d->short_list, d->temp) == 1)
		i = i + 0;
	if (possible_comm(d->temp[0]) == 1 || (d->work_tries > 0 && length_arr(d->short_list, d->temp) == 0))
		return ;
	input_init(&c2, c->ac, c->av);
	while (d->temp[i] != '0')
	{
		if (c2.b_[0] == '0' && possible_comm(d->temp[i]) == 1)
			break ;
		specifier(line_to_int(list[d->temp[i] - 'a']), &c2);
		i++;
	}
	if (sorted(&c2) == 1)
	{
		i = 0;
		d->work_tries++;
		if (d->short_len == 0 || length_arr(d->short_list, d->temp) == 1)
		{
			while (d->temp[i] != '0')
			{
				if (d->short_list[i][0] != '0')
					free(d->short_list[i]);
				d->short_list[i] = ft_strdup(list[d->temp[i] - 'a']);
				i++;
			}
			d->short_list[i][0] = '0';
			d->short_len = i;
		}
	}
	free(c2.a);
	free(c2.a_);
	free(c2.b);
	free(c2.b_);
}

void	brute_force(t_data *d, t_check *c)
{
	static char	list[11] = {'a', 'b', 'c', 'd', 'e', 'f',
		'g', 'h', 'i', 'j', 'k'};
	int			i;

	i = 0;
	d->i++;
	while (i < 11 && d->i < d->max_commands)
	{
		d->temp[d->i] = list[i];
		try_option(d, c);
		if (d->i < d->max_commands)
			brute_force(d, c);
		i++;
	}
	d->temp[d->i] = '0';
	d->i--;
}

void	algorithm(t_check *check)
{
	t_data		data;
	int			i;

	i = 0;
	if (init_push(&data, check) == 0)
		return ;
	brute_force(&data, check);
	printf("%'lld tries done\n%'d functioning combinations\n", data.tries, data.work_tries);
	printf("shortest try of %d command(s):\n", data.short_len);
	while (data.short_list[i][0] != '0')
	{
		printf("%s", data.short_list[i]);
		i++;
	}
}
