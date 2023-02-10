/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:45:03 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/10 18:39:47 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_pile *pile)
{
	int	i;
	int	min;
	int	min_index;

	i = 1;
	min = pile->tab[0];
	min_index = 0;
	while (i < pile->size)
	{
		if (pile->tab[i] < min)
		{
			min = pile->tab[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	is_max(int a, t_pile *pile)
{
	int	i;

	i = 0;
	while (i < pile->size)
	{
		if (pile->tab[i] > a)
			return (0);
		i++;
	}
	return (1);
}

int	find_next_index(int a, t_pile *pile)
{
	int	i;
	int	diff;
	int	next_index;

	if (pile->size < 2)
		return (0);
	if (is_max(a, pile) == 1)
		return (find_min_index(pile));
	i = 0;
	if (a < pile->tab[0])
		diff = pile->tab[0] - a;
	else
		diff = 2147483647;
	next_index = 0;
	while (i++ < pile->size)
	{
		if (pile->tab[i] < a)
			i++;
		if ((pile->tab[i] > a) && (pile->tab[i] - a) < diff)
		{
			diff = pile->tab[i] - a;
			next_index = i;
		}
	}
	return (next_index);
}

int	find_moving_value(t_pile *pile_a, t_pile *pile_b)
{
	int	index_a;
	int	index_b;
	int	min_actions;
	int	nb_actions;
	int	index_moving_value;

	index_b = 0;
	index_a = find_next_index(pile_b->tab[index_b], pile_a);
	min_actions = count_actions(pile_a, pile_b, index_a, index_b);
	index_moving_value = 0;
	while (index_b < pile_b->size)
	{
		index_a = find_next_index(pile_b->tab[index_b], pile_a);
		nb_actions = count_actions(pile_a, pile_b, index_a, index_b);
		if (nb_actions < min_actions)
		{
			min_actions = nb_actions;
			index_moving_value = index_b;
		}
		index_b++;
	}
	return (index_moving_value);
}
