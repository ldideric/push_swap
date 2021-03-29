/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/27 17:16:25 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/29 13:27:09 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#include <stdio.h>

int	init_push(t_data *d, t_check *c)
{
	int	i;

	i = 0;
	d->i = -1;
	d->tries = 0;
	d->work_tries = 0;
	d->max_commands = c->len + 5;
	d->short_list = malloc(sizeof(char *) * d->max_commands);
	d->temp = malloc(sizeof(char) * d->max_commands + 1);
	if (d->short_list == NULL || d->temp == NULL)
		return (err_print("Error\n"));
	while (i < c->len)
	{
		d->temp[i] = '0';
		d->short_list[i] = malloc(sizeof(char) * 5);
		if (d->short_list[i] == NULL)
			return (err_print("Error\n"));
		i++;
	}
	return (1);
}

void	try_option(t_data *d, t_check *c)
{
	// static char	*list[11] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n",
	// 	"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	d->tries++;
	if (d->tries % 1000000 == 0)
		printf("%lld\n", d->tries);
	c->len = 0;
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
		// try_option(d, c);
		d->tries++;
		if (d->tries % 100000000 == 0)
			printf("%lld tried\n", d->tries);
		if (d->i < d->max_commands)
			brute_force(d, c);
		i++;
	}
	d->temp[d->i] = '0';
	d->i--;
}

// void	brute_force(t_data *d, t_check *c)
// {
// 	static char	*list[4] = {"A.", "B.", "C.", "ye"};
// 	int			i;

// 	i = 0;
// 	d->i++;
// 	while (i < 4 && d->i < d->max_commands)
// 	{
// 		d->temp[d->i] = list[i];
// 		try_option(d, c);
// 		ft_printf("%s|%s|%s\n", d->temp[0], d->temp[1], d->temp[2]);
// 		if (d->i < d->max_commands)
// 			brute_force(d, c);
// 		i++;
// 	}
// 	d->temp[d->i] = "";
// 	d->i--;
// }

void	algorithm(t_check *check)
{
	t_data		data;

	if (init_push(&data, check) == 0)
		return ;
	brute_force(&data, check);
	printf("%lld", data.tries);
}
