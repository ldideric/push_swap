/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:02:10 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/27 17:01:33 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_check		check;

	if (!validate_input(ac, av))
		return (err_print("Error\n"));
	if (!input_init(&check, ac, av))
		return (err_print("Error\n"));
	reader(&check);
	return (0);
}
