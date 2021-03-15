/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:42:53 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/15 18:51:15 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void	specifier(int num, t_check *c)
{
	static const t_spec	spec[12] = {
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
	if (ft_strcmp(line, "sa") == 0)
		return (1);
	else if (ft_strcmp(line, "sb") == 0)
		return (2);
	else if (ft_strcmp(line, "ss") == 0)
		return (3);
	else if (ft_strcmp(line, "pa") == 0)
		return (4);
	else if (ft_strcmp(line, "pb") == 0)
		return (5);
	else if (ft_strcmp(line, "ra") == 0)
		return (6);
	else if (ft_strcmp(line, "rb") == 0)
		return (7);
	else if (ft_strcmp(line, "rr") == 0)
		return (8);
	else if (ft_strcmp(line, "rra") == 0)
		return (9);
	else if (ft_strcmp(line, "rrb") == 0)
		return (10);
	else if (ft_strcmp(line, "rrr") == 0)
		return (11);
	else
		return (0);
}

void	algorithm(t_check *check)
{
	char	*line;

	line = NULL;
	while (!sorted(check))
	{
		read(1, line, 256);
		specifier(line_to_int(line), check);
	}
	ft_printf("OK");
}
