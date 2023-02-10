/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:50:50 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/07 14:55:35 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
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
int		sa(t_pile *pile_a);
int		sb(t_pile *pile_b);
int		ss(t_pile *pile_a, t_pile *pile_b);
int		pa(t_pile *pile_a, t_pile *pile_b);
int		pb(t_pile *pile_a, t_pile *pile_b);
int		ra(t_pile *pile_a);
int		rb(t_pile *pile_b);
int		rr(t_pile *pile_a, t_pile *pile_b);
int		rra(t_pile *pile_a);
int		rrb(t_pile *pile_b);
int		rrr(t_pile *pile_a, t_pile *pile_b);
// check
int		check_actions1(t_pile *pile_a, t_pile *pile_b, char *actions, int i);
int		check_actions2(t_pile *pile_a, t_pile *pile_b, char *actions, int i);
void	write_message(t_pile *pile_a, t_pile *pile_b, int i);
void	is_sorted(t_pile *pile_a, t_pile *pile_b);
void	check(t_pile *pile_a, t_pile *pile_b);

#endif