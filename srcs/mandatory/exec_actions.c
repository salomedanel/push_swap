/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:27:19 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/04 13:56:11 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_pile *pile_a, t_pile *pile_b, int index_a, int index_b)
{
	int	leftover;

	if (index_a >= index_b)
	{
		leftover = index_a - index_b;
		while (index_b-- > 0)
			rr(pile_a, pile_b);
		while (leftover > 0)
		{
			ra(pile_a);
			leftover--;
		}
	}
	else
	{
		leftover = index_b - index_a;
		while (index_a-- > 0)
			rr(pile_a, pile_b);
		while (leftover > 0)
		{
			rb(pile_b);
			leftover--;
		}
	}
}

void	reverse_rotate(t_pile *pile_a, t_pile *pile_b, int index_a, int index_b)
{
	int	leftover;

	if ((pile_a->size - index_a) >= (pile_b->size - index_b))
	{
		leftover = (pile_a->size - index_a) - (pile_b->size - index_b);
		while (index_b++ < pile_b->size)
			rrr(pile_a, pile_b);
		while (leftover > 0)
		{
			rra(pile_a);
			leftover--;
		}
	}
	else
	{
		leftover = (pile_b->size - index_b) - (pile_a->size - index_a);
		while (index_a++ < pile_a->size)
			rrr(pile_a, pile_b);
		while (leftover > 0)
		{
			rrb(pile_b);
			leftover--;
		}
	}
}

void	different_rr(t_pile *pile_a, t_pile *pile_b, int index_a, int index_b)
{
	while (index_a <= pile_a->size / 2 && index_a > 0)
	{
		ra(pile_a);
		index_a--;
	}
	while (index_a > pile_a->size / 2 && index_a < pile_a->size)
	{
		rra(pile_a);
		index_a++;
	}
	while (index_b <= pile_b->size / 2 && index_b > 0)
	{
		rb(pile_b);
		index_b--;
	}
	while (index_b > pile_b->size / 2 && index_b < pile_b->size)
	{
		rrb(pile_b);
		index_b++;
	}
}

void	run_actions(t_pile *pile_a, t_pile *pile_b, int index_a, int index_b)
{
	if ((index_a <= pile_a->size / 2) && (index_b <= pile_b->size / 2))
		rotate(pile_a, pile_b, index_a, index_b);
	else if ((index_a > pile_a->size / 2) && (index_b > pile_b->size / 2))
		reverse_rotate(pile_a, pile_b, index_a, index_b);
	else
		different_rr(pile_a, pile_b, index_a, index_b);
	pa(pile_a, pile_b);
}

void	last_actions(t_pile *pile_a)
{
	int	min_index;

	min_index = find_min_index(pile_a);
	if (min_index <= pile_a->size / 2)
	{
		while (min_index != 0)
		{
			ra(pile_a);
			min_index = find_min_index(pile_a);
		}
	}
	else
	{
		while (min_index != 0)
		{
			rra(pile_a);
			min_index = find_min_index(pile_a);
		}
	}
}
