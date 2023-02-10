/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:29:05 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/09 11:43:28 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_pile *pile_a)
{
	int	i;

	i = 0;
	if (pile_a->size == 0)
		return (0);
	if (pile_a->size == 1)
		return (1);
	while (i < pile_a->size - 1)
	{
		if (pile_a->tab[i] > pile_a->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_three(t_pile *pile)
{
	if ((pile->tab[0] < pile->tab[1]) && (pile->tab[1] > pile->tab[2])
		&& (pile->tab[0] < pile->tab[2]))
	{
		sa(pile);
		ra(pile);
	}
	if ((pile->tab[0] > pile->tab[1]) && (pile->tab[1] < pile->tab[2])
		&& (pile->tab[0] < pile->tab[2]))
		sa(pile);
	if ((pile->tab[0] < pile->tab[1]) && (pile->tab[1] > pile->tab[2])
		&& (pile->tab[0] > pile->tab[2]))
		rra(pile);
	if ((pile->tab[0] > pile->tab[1]) && (pile->tab[1] < pile->tab[2])
		&& (pile->tab[0] > pile->tab[2]))
		ra(pile);
	if ((pile->tab[0] > pile->tab[1]) && (pile->tab[1] > pile->tab[2])
		&& (pile->tab[0] > pile->tab[2]))
	{
		ra(pile);
		sa(pile);
	}
}

int	getmin(t_pile *pile_a)
{
	int	i;
	int	min;
	int	min_index;

	i = 1;
	min = pile_a->tab[0];
	min_index = 0;
	while (i < pile_a->size)
	{
		if (pile_a->tab[i] < min)
		{
			min = pile_a->tab[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	push_min(t_pile *pile_a, t_pile *pile_b)
{
	int	index;

	index = getmin(pile_a);
	if (index <= 2)
	{
		while (index > 0)
		{
			ra(pile_a);
			index--;
		}
	}
	if (index > 2)
	{
		while (index < pile_a->size)
		{
			rra(pile_a);
			index++;
		}
	}
	pb(pile_a, pile_b);
}

void	sort_small(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->size == 2 && sorted(pile_a) == 0)
		sa(pile_a);
	if (pile_a->size == 3)
		sort_three(pile_a);
	if (pile_a->size == 4)
	{
		push_min(pile_a, pile_b);
		sort_three(pile_a);
		pa(pile_a, pile_b);
	}
	if (pile_a->size == 5)
	{
		push_min(pile_a, pile_b);
		push_min(pile_a, pile_b);
		sort_three(pile_a);
		pa(pile_a, pile_b);
		pa(pile_a, pile_b);
	}
}
