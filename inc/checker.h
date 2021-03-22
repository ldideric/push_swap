/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:08:45 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/22 17:49:01 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

# include <stdlib.h>
# include <unistd.h>

typedef struct s_check
{
	int			ac;
	char		**av;
	int			len;
	int			*a;
	int			*a_;
	int			*b;
	int			*b_;
}				t_check;

typedef void	(*t_func)(t_check *c);

int				validate_input(int ac, char **av);
int				input_init(t_check *check, int ac, char **av);

void			algorithm(t_check *check);
int				sorted(t_check *c);


void			print_arr(t_check *c);


void			ex_err(t_check *c);
void			ex_sa(t_check *c);
void			ex_sb(t_check *c);
void			ex_ss(t_check *c);
void			ex_pa(t_check *c);
void			ex_pb(t_check *c);
void			ex_ra(t_check *c);
void			ex_rb(t_check *c);
void			ex_rr(t_check *c);
void			ex_rra(t_check *c);
void			ex_rrb(t_check *c);
void			ex_rrr(t_check *c);

void			ex_push_down(t_check *check, int **c_, char ab);

#endif
