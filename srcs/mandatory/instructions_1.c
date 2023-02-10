/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:21:27 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/05 13:42:42 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pile *pile_a)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (pile_a->size <= 1)
		return ;
	tmp = pile_a->tab[0];
	pile_a->tab[0] = pile_a->tab[1];
	pile_a->tab[1] = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (pile_b->size <= 1)
		return ;
	tmp = pile_b->tab[0];
	pile_b->tab[0] = pile_b->tab[1];
	pile_b->tab[1] = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (pile_a->size <= 1)
		return ;
	tmp = pile_a->tab[0];
	pile_a->tab[0] = pile_a->tab[1];
	pile_a->tab[1] = tmp;
	i = 0;
	tmp = 0;
	if (pile_b->size <= 1)
		return ;
	tmp = pile_b->tab[0];
	pile_b->tab[0] = pile_b->tab[1];
	pile_b->tab[1] = tmp;
	write(1, "ss\n", 3);
}

void	pa(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = pile_b->tab[0];
	if (pile_b->size == 0)
		return ;
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
	write(1, "pa\n", 3);
}

void	pb(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = pile_a->tab[0];
	if (pile_a->size == 0)
		return ;
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
	write(1, "pb\n", 3);
}
