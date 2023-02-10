/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:50:50 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/10 18:29:07 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pile
{
	int	*tab;
	int	size;
}		t_pile;

// parsing
void	ft_error(char *arg, int err, int *pile_a);
int		ft_atoil(char *nptr, int *pile_a);
int		check_ifnumber(char **argv, int argc, int *pile_a);
int		check_double(int *pile_a, int size);
int		*ft_parsing(int *pile_a, char **argv, int argc);
// instructions
void	sa(t_pile *pile_a);
void	sb(t_pile *pile_b);
void	ss(t_pile *pile_a, t_pile *pile_b);
void	pa(t_pile *pile_a, t_pile *pile_b);
void	pb(t_pile *pile_a, t_pile *pile_b);
void	ra(t_pile *pile_a);
void	rb(t_pile *pile_b);
void	rr(t_pile *pile_a, t_pile *pile_b);
void	rra(t_pile *pile_a);
void	rrb(t_pile *pile_b);
void	rrr(t_pile *pile_a, t_pile *pile_b);
// sorting
int		sorted(t_pile *pile_a);
void	sort_three(t_pile *pile);
int		getmin(t_pile *pile_a);
void	push_min(t_pile *pile_a, t_pile *pile_b);
void	sort_small(t_pile *pile_a, t_pile *pile_b);
// find_index
int		find_min_index(t_pile *pile);
int		find_next_index(int a, t_pile *pile);
int		is_max(int a, t_pile *pile);
int		find_moving_value(t_pile *pile_a, t_pile *pile_b);
// sort_big
int		count_actions(t_pile *pile_a, t_pile *pile_b, int index_a, int index_b);
int		count_join_actions(int count_ra, int count_rb, int count_rra,
			int count_rrb);
void	sort_big(t_pile *pile_a, t_pile *pile_b);
// exec_action
void	rotate(t_pile *pile_a, t_pile *pile_b, int index_a, int index_b);
void	reverse_rotate(t_pile *pile_a, t_pile *pile_b, int index_a,
			int index_b);
void	different_rr(t_pile *pile_a, t_pile *pile_b, int index_a, int index_b);
void	run_actions(t_pile *pile_a, t_pile *pile_b, int index_a, int index_b);
void	last_actions(t_pile *pile_a);
// main
void	sort(t_pile *pile_a, t_pile *pile_b);

#endif
