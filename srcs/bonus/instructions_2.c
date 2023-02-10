/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:33:35 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/07 14:52:56 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ra(t_pile *pile_a)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (pile_a->size == 0)
		return (1);
	tmp = pile_a->tab[0];
	while (i < pile_a->size - 1)
	{
		pile_a->tab[i] = pile_a->tab[i + 1];
		i++;
	}
	pile_a->tab[i] = tmp;
	return (1);
}

int	rb(t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (pile_b->size == 0)
		return (1);
	tmp = pile_b->tab[0];
	while (i < pile_b->size)
	{
		pile_b->tab[i] = pile_b->tab[i + 1];
		i++;
	}
	pile_b->tab[i - 1] = tmp;
	return (1);
}

int	rr(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (pile_a->size == 0)
		return (1);
	tmp = pile_a->tab[0];
	while (i < pile_a->size - 1)
	{
		pile_a->tab[i] = pile_a->tab[i + 1];
		i++;
	}
	pile_a->tab[i] = tmp;
	i = 0;
	if (pile_b->size == 0)
		return (1);
	tmp = pile_b->tab[0];
	while (i < pile_b->size)
	{
		pile_b->tab[i] = pile_b->tab[i + 1];
		i++;
	}
	pile_b->tab[i - 1] = tmp;
	return (1);
}
