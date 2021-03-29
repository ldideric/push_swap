/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:42:53 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/27 17:01:33 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	specifier(int num, t_check *c)
{
	static const t_func	spec[12] = {
		[0] = &ex_err,
		[1] = &ex_sa,
		[2] = &ex_sb,
		[3] = &ex_ss,
		[4] = &ex_pa,
		[5] = &ex_pb,
		[6] = &ex_ra,
		[7] = &ex_rb,
		[8] = &ex_rr,
		[9] = &ex_rra,
		[10] = &ex_rrb,
		[11] = &ex_rrr,
	};

	spec[num](c);
}

static int	line_to_int(char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(line, "sb\n") == 0)
		return (2);
	else if (ft_strcmp(line, "ss\n") == 0)
		return (3);
	else if (ft_strcmp(line, "pa\n") == 0)
		return (4);
	else if (ft_strcmp(line, "pb\n") == 0)
		return (5);
	else if (ft_strcmp(line, "ra\n") == 0)
		return (6);
	else if (ft_strcmp(line, "rb\n") == 0)
		return (7);
	else if (ft_strcmp(line, "rr\n") == 0)
		return (8);
	else if (ft_strcmp(line, "rra\n") == 0)
		return (9);
	else if (ft_strcmp(line, "rrb\n") == 0)
		return (10);
	else if (ft_strcmp(line, "rrr\n") == 0)
		return (11);
	else
		return (0);
}

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
