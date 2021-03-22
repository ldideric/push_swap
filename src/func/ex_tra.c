/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex_tra.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 17:48:15 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/22 19:13:16 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	ex_push_down(t_check *check, int **c__, char ab)
{
	int	*c;
	int	*c_;
	int	i;

	c_ = *c__;
	i = check->len - 1;
	if (ab == 'a')
		c = check->a;
	else
		c = check->b;
	while (i > 0 && c_[i] == 0)
		i--;
	while (i >= 0)
	{
		c[i + 1] = c[i];
		i--;
	}
}
