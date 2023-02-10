/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:39:52 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/05 13:02:39 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pile *pile_a)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (pile_a->size == 0)
		return ;
	tmp = pile_a->tab[0];
	while (i < pile_a->size - 1)
	{
		pile_a->tab[i] = pile_a->tab[i + 1];
		i++;
	}
	pile_a->tab[i] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (pile_b->size == 0)
		return ;
	tmp = pile_b->tab[0];
	while (i < pile_b->size)
	{
		pile_b->tab[i] = pile_b->tab[i + 1];
		i++;
	}
	pile_b->tab[i - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (pile_a->size == 0)
		return ;
	tmp = pile_a->tab[0];
	while (i < pile_a->size)
	{
		pile_a->tab[i] = pile_a->tab[i + 1];
		i++;
	}
	pile_a->tab[i - 1] = tmp;
	i = 0;
	if (pile_b->size == 0)
		return ;
	tmp = pile_b->tab[0];
	while (i < pile_b->size)
	{
		pile_b->tab[i] = pile_b->tab[i + 1];
		i++;
	}
	pile_b->tab[i - 1] = tmp;
	write(1, "rr\n", 3);
}
