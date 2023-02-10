/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:45:49 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/10 18:52:30 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_actions1(t_pile *pile_a, t_pile *pile_b, char *actions, int i)
{
	if (ft_strcmp(actions, "sa\n") == 0)
		i = sa(pile_a);
	else if (ft_strcmp(actions, "sb\n") == 0)
		i = sb(pile_b);
	else if (ft_strcmp(actions, "ss\n") == 0)
		i = ss(pile_a, pile_b);
	else if (ft_strcmp(actions, "pa\n") == 0)
		i = pa(pile_a, pile_b);
	else if (ft_strcmp(actions, "pb\n") == 0)
		i = pb(pile_a, pile_b);
	return (i);
}

int	check_actions2(t_pile *pile_a, t_pile *pile_b, char *actions, int i)
{
	if (ft_strcmp(actions, "ra\n") == 0)
		i = ra(pile_a);
	else if (ft_strcmp(actions, "rb\n") == 0)
		i = rb(pile_b);
	else if (ft_strcmp(actions, "rr\n") == 0)
		i = rr(pile_a, pile_b);
	else if (ft_strcmp(actions, "rra\n") == 0)
		i = rra(pile_a);
	else if (ft_strcmp(actions, "rrb\n") == 0)
		i = rrb(pile_b);
	else if (ft_strcmp(actions, "rrr\n") == 0)
		i = rrr(pile_a, pile_b);
	return (i);
}
