/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/27 15:22:55 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/27 17:16:03 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//download new norminette + extension
//remove norminette+

// try brute forcing options for fun :D

/*
How many different numbers are possible? 11
How many numbers are used? 10
Is the order of the numbers important? Yes
Can you repeat a number? Yes

Short Answer: 2.5937424601e+10
Full Answer: 25937424601
*/

#include <push_swap.h>

int	main(int ac, char **av)
{
	t_check		check;

	if (!validate_input(ac, av))
		return (err_print("Error\n"));
	if (!input_init(&check, ac, av))
		return (err_print("Error\n"));
	algorithm(&check);
	return (0);
}
