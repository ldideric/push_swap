/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:08:45 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/08 18:03:16 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

# include <stdlib.h>

typedef struct s_check
{
	int			ac;
	char		**av;
	int			len;
	int			*a;
	int			*b;
}				t_check;

#endif