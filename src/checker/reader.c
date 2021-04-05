/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:42:53 by ldideric      #+#    #+#                 */
/*   Updated: 2021/04/02 13:52:03 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reader(t_check *check)
{
	char	*line;
	int		ret;

	line = malloc(sizeof(char) * 5);
	while (!sorted(check))
	{
		ret = read(STDIN_FILENO, line, 5);
		if (ret == -1 || ret > 4)
			return ((void)err_print("Error\n"));
		if (ret > 0)
		{
			ret = line_to_int(line);
			if (ret != 0)
				specifier(ret, check);
			else
				return ((void)err_print("Error\n"));
		}
	}
	free(line);
	ft_printf("OK\n");
}
