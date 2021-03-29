/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:08:45 by ldideric      #+#    #+#                 */
/*   Updated: 2021/03/29 13:18:51 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_data
{
	long long	tries;
	int			work_tries;
	char		**short_list;
	char		*temp;
	int			i;
	int			max_commands;
}				t_data;

typedef void	(*t_func)(t_check *c);

int				validate_input(int ac, char **av);
int				input_init(t_check *check, int ac, char **av);

void			reader(t_check *check);
int				sorted(t_check *c);


void			algorithm(t_check *check);

int				err_print(char *s);

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
