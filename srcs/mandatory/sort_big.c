/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:14:55 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/10 18:28:37 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_actions(t_pile *pile_a, t_pile *pile_b, int index_a, int index_b)
{
	int	count_ra;
	int	count_rb;
	int	count_rra;
	int	count_rrb;

	count_ra = 0;
	count_rb = 0;
	count_rra = 0;
	count_rrb = 0;
	if (index_a <= pile_a->size / 2)
		count_ra = index_a;
	if (index_a > pile_a->size / 2)
		count_rra = pile_a->size - index_a;
	if (index_b <= pile_b->size / 2)
		count_rb = index_b;
	if (index_b > pile_b->size / 2)
		count_rrb = pile_b->size - index_b;
	return (count_join_actions(count_ra, count_rb, count_rra, count_rrb) + 1);
}

int	count_join_actions(int count_ra, int count_rb, int count_rra, int count_rrb)
{
	int	tot_actions;

	if (count_ra > count_rb)
		tot_actions = count_ra;
	else
		tot_actions = count_rb;
	if (count_rra > count_rrb)
		tot_actions = tot_actions + count_rra;
	else
		tot_actions = tot_actions + count_rrb;
	return (tot_actions);
}

void	sort_big(t_pile *pile_a, t_pile *pile_b)
{
	int	to_move;
	int	move_to;

	move_to = 0;
	to_move = 0;
	while (pile_a->size > 3)
		pb(pile_a, pile_b);
	sort_three(pile_a);
	while (pile_b->size > 0)
	{
		to_move = find_moving_value(pile_a, pile_b);
		move_to = find_next_index(pile_b->tab[to_move], pile_a);
		run_actions(pile_a, pile_b, move_to, to_move);
	}
	last_actions(pile_a);
}
