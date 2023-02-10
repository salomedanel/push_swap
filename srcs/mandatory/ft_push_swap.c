/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:11:35 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/10 18:29:21 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->size <= 5)
		sort_small(pile_a, pile_b);
	else
		sort_big(pile_a, pile_b);
}

void	print(t_pile *pile_a)
{
	int	i;

	i = 0;
	while (i < pile_a->size)
	{
		printf("tab_a[%d] = %d\n", i, pile_a->tab[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_pile	pile_a;
	t_pile	pile_b;

	pile_a.size = argc - 1;
	pile_b.size = 0;
	if (argc <= 1)
		return (0);
	pile_a.tab = malloc(sizeof(int) * (argc - 1));
	if (pile_a.tab == NULL)
		return (0);
	pile_a.tab = ft_parsing(pile_a.tab, argv, argc);
	pile_b.tab = malloc(sizeof(int) * (argc - 1));
	if (pile_b.tab == NULL)
	{
		free(pile_a.tab);
		return (0);
	}
	if (sorted(&pile_a) == 1)
		return (free(pile_a.tab), free(pile_b.tab), 0);
	sort(&pile_a, &pile_b);
	return (free(pile_a.tab), free(pile_b.tab), 0);
}
