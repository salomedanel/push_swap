/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:57:46 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/05 13:09:19 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pile *pile_a)
{
	int	i;
	int	tmp;

	i = pile_a->size - 1;
	tmp = 0;
	if (pile_a->size <= 1)
		return ;
	tmp = pile_a->tab[pile_a->size - 1];
	while (i > 0)
	{
		pile_a->tab[i] = pile_a->tab[i - 1];
		i--;
	}
	pile_a->tab[0] = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = pile_b->size - 1;
	tmp = 0;
	if (pile_b->size <= 1)
		return ;
	tmp = pile_b->tab[pile_b->size - 1];
	while (i > 0)
	{
		pile_b->tab[i] = pile_b->tab[i - 1];
		i--;
	}
	pile_b->tab[0] = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = pile_a->size;
	tmp = 0;
	if (pile_a->size <= 1)
		return ;
	tmp = pile_a->tab[pile_a->size - 1];
	while (--i > 0)
		pile_a->tab[i] = pile_a->tab[i - 1];
	pile_a->tab[i] = pile_a->tab[0];
	pile_a->tab[0] = tmp;
	i = pile_b->size;
	if (pile_b->size <= 1)
		return ;
	tmp = pile_b->tab[pile_b->size - 1];
	while (--i > 0)
		pile_b->tab[i] = pile_b->tab[i - 1];
	pile_b->tab[i] = pile_b->tab[0];
	pile_b->tab[0] = tmp;
	write(1, "rrr\n", 4);
}
