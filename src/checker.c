/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:02:10 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/15 17:13:02 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int	main(int ac, char **av)
{
	t_check		check;

	if (!validate_input(ac, av))
		return (0);
	if (!input_init(&check, ac, av))
		return (0);
	algorithm(&check);
	return (0);
}
