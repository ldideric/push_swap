/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extras.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 17:12:38 by ldideric      #+#    #+#                 */
/*   Updated: 2021/04/02 14:16:39 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	sorted(t_check *c)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < c->len)
	{
		if (c->b_[i] == 1)
			return (0);
		i++;
	}
	tmp = c->a[0];
	i = 1;
	while (i < c->len)
	{
		if (!(tmp < c->a[i]))
			return (0);
		tmp = c->a[i];
		i++;
	}
	return (1);
}

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
	check->a_ = malloc(sizeof(int) * check->len);
	check->b_ = malloc(sizeof(int) * check->len);
	if (check->a == NULL || check->b == NULL
		|| check->a_ == NULL || check->b_ == NULL)
		return (0);
	while (i < check->len)
	{
		check->a[i] = ft_atoi(av[i + 1]);
		check->a_[i] = 1;
		check->b[i] = 0;
		check->b_[i] = 0;
		i++;
	}
	return (1);
}

int	validate_input(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (!ft_ismatch(av[i][j], "\t 0123456789-"))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	print_arr(t_check *c)
{
	int	i;

	i = 0;
	while (i < c->len)
	{
		ft_printf("%5i|(%i)|%5i|(%i)\n", c->a[i], c->a_[i], c->b[i], c->b_[i]);
		i++;
	}
	ft_printf("\n");
}

int	err_print(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (0);
}

long long	power(int base, int exp)
{
	long long	result;

	result = 1;
	while (exp != 0)
	{
		result *= base;
		--exp;
	}
	return (result);
}

int	length_arr(char **old, char *new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (new[i] != '0')
		i++;
	while (old[j][0] != '0')
		j++;
	if (i <= j)
		return (1);
	return (0);
}