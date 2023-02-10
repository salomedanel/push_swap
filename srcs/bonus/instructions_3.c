/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:33:45 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/07 14:53:00 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rra(t_pile *pile_a)
{
	int	i;
	int	tmp;

	i = pile_a->size - 1;
	tmp = 0;
	if (pile_a->size <= 1)
		return (1);
	tmp = pile_a->tab[pile_a->size - 1];
	while (i > 0)
	{
		pile_a->tab[i] = pile_a->tab[i - 1];
		i--;
	}
	pile_a->tab[0] = tmp;
	return (1);
}

int	rrb(t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = pile_b->size - 1;
	tmp = 0;
	if (pile_b->size <= 1)
		return (1);
	tmp = pile_b->tab[pile_b->size - 1];
	while (i > 0)
	{
		pile_b->tab[i] = pile_b->tab[i - 1];
		i--;
	}
	pile_b->tab[0] = tmp;
	return (1);
}

int	rrr(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = pile_a->size;
	tmp = 0;
	if (pile_a->size <= 1)
		return (1);
	tmp = pile_a->tab[pile_a->size - 1];
	while (--i > 0)
		pile_a->tab[i] = pile_a->tab[i - 1];
	pile_a->tab[i] = pile_a->tab[0];
	pile_a->tab[0] = tmp;
	i = pile_b->size;
	if (pile_b->size <= 1)
		return (1);
	tmp = pile_b->tab[pile_b->size - 1];
	while (--i > 0)
		pile_b->tab[i] = pile_b->tab[i - 1];
	pile_b->tab[i] = pile_b->tab[0];
	pile_b->tab[0] = tmp;
	return (1);
}
