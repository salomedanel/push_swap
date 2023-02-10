/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:33:24 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/07 14:52:54 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	sa(t_pile *pile_a)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (pile_a->size <= 1)
		return (1);
	tmp = pile_a->tab[0];
	pile_a->tab[0] = pile_a->tab[1];
	pile_a->tab[1] = tmp;
	return (1);
}

int	sb(t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (pile_b->size <= 1)
		return (1);
	tmp = pile_b->tab[0];
	pile_b->tab[0] = pile_b->tab[1];
	pile_b->tab[1] = tmp;
	return (1);
}

int	ss(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (pile_a->size <= 1)
		return (1);
	tmp = pile_a->tab[0];
	pile_a->tab[0] = pile_a->tab[1];
	pile_a->tab[1] = tmp;
	i = 0;
	tmp = 0;
	if (pile_b->size <= 1)
		return (1);
	tmp = pile_b->tab[0];
	pile_b->tab[0] = pile_b->tab[1];
	pile_b->tab[1] = tmp;
	return (1);
}

int	pa(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = pile_b->tab[0];
	if (pile_b->size == 0)
		return (1);
	while (i < (pile_b->size - 1))
	{
		pile_b->tab[i] = pile_b->tab[i + 1];
		i++;
	}
	pile_b->tab[i] = 0;
	i = pile_a->size;
	while (i > 0)
	{
		pile_a->tab[i] = pile_a->tab[i - 1];
		i--;
	}
	pile_a->tab[0] = tmp;
	pile_b->size--;
	pile_a->size++;
	return (1);
}

int	pb(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = pile_a->tab[0];
	if (pile_a->size == 0)
		return (1);
	while (i < (pile_a->size - 1))
	{
		pile_a->tab[i] = pile_a->tab[i + 1];
		i++;
	}
	pile_a->tab[i] = 0;
	i = pile_b->size;
	while (i > 0)
	{
		pile_b->tab[i] = pile_b->tab[i - 1];
		i--;
	}
	pile_b->tab[0] = tmp;
	pile_a->size--;
	pile_b->size++;
	return (1);
}
