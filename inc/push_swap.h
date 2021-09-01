/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:08:45 by ldideric      #+#    #+#                 */
/*   Updated: 2021/09/01 13:03:32 by ldideric      ########   odam.nl         */
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
	int			*fixed;
	int			i;
	int			less;
	int			less_i;
	int			mid_step;
	int			s_start;
}				t_data;

typedef void	(*t_func)(t_check *c);

int				validate_input(int ac, char **av);
int				input_init(t_check *check, int ac, char **av);

void			reader(t_check *check);
int				sorted(t_check *c);

void			specifier(int num, t_check *c);
int				line_to_int(char *line);

long long		power(int base, int exp);
int				length_arr(char **old, char *new);
int				possible_comm(char c);

void			algorithm(t_check *check);
void			quick_sort(t_data *d, t_check *c);
void			sort_mid(t_data *d, t_check *c);
void			find_mid_split(t_data *d, t_check *c, int a);
void			use_func(char *func, t_check *c);

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
