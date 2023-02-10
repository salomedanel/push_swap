/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:40:48 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/10 18:54:35 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	write_message(t_pile *pile_a, t_pile *pile_b, int i)
{
	free(pile_a->tab);
	free(pile_b->tab);
	if (i == 0)
		write(1, "Error\n", 6);
	else if (i == 1)
		write(1, "OK\n", 3);
	else if (i == 2)
		write(1, "KO\n", 3);
	exit(0);
}

void	is_sorted(t_pile *pile_a, t_pile *pile_b)
{
	int	i;

	i = 0;
	while (i < pile_a->size - 1)
	{
		if (pile_a->tab[i] > pile_a->tab[i + 1])
			write_message(pile_a, pile_b, 2);
		i++;
	}
	if (i == pile_a->size - 1 && pile_b->size == 0)
		write_message(pile_a, pile_b, 1);
	write_message(pile_a, pile_b, 2);
}

void	check(t_pile *pile_a, t_pile *pile_b)
{
	char	*actions;
	int		i;

	i = 0;
	actions = 0;
	while (1)
	{
		actions = get_next_line(0, 0);
		if (!actions)
			break ;
		i = check_actions1(pile_a, pile_b, actions, i);
		i = check_actions2(pile_a, pile_b, actions, i);
		if (i != 1)
		{
			free(actions);
			get_next_line(1, 1);
			write_message(pile_a, pile_b, 0);
		}
		free(actions);
		i = 0;
	}
	get_next_line(1, 1);
	is_sorted(pile_a, pile_b);
}

int	main(int argc, char **argv)
{
	t_pile	pile_a;
	t_pile	pile_b;

	pile_a.size = argc - 1;
	pile_b.size = 0;
	if (argc < 2)
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
	check(&pile_a, &pile_b);
	return (free(pile_a.tab), free(pile_b.tab), 0);
}
