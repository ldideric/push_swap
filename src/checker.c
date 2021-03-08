/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:02:10 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/08 18:27:34 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int	input_init(t_check *check, int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 3)
		return (0);
	check->ac = ac;
	check->av = av;
	check->len = ac - 1;
	check->a = malloc(sizeof(int) * check->len);
	check->b = malloc(sizeof(int) * check->len);
	if (check->a == NULL || check->b == NULL)
		return (0);
	while (i < check->len)
	{
		check->a[i] = ft_atoi(av[i + 1]);
		i++;
	}
	ft_printf("%i, %i, %i, %i", check->a[0], check->a[1], check->a[2], check->a[3]);
	return (1);
}

int	main(int ac, char **av)
{
	t_check		check;

	if (!input_init(&check, ac, av))
		return (0);
	return (0);
}
