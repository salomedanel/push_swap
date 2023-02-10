/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdanel <sdanel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:29:13 by sdanel            #+#    #+#             */
/*   Updated: 2023/01/04 19:22:09 by sdanel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *arg, int err, int *pile_a)
{
	ft_putstr_fd(arg, 2);
	free(pile_a);
	exit(err);
}	

int	ft_atoil(char *nptr, int *pile_a)
{
	long int	i;
	long int	sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!nptr)
		return (0);
	if (nptr[0] == '-')
	{
		sign = 1 * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	result = result * sign;
	if (result > 2147483647 || result < -2147483648)
		ft_error("Error\n", 1, pile_a);
	return (result);
}

int	check_ifnumber(char **argv, int argc, int *pile_a)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (argv[i++][0] == '\0')
			ft_error("Error\n", 2, pile_a);
	}
	i = 0;
	while (++i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-' && argv[i][j - 1] != '-' && j == 0)
				j++;
			if ((argv[i][j] >= '0' && argv[i][j] <= '9'))
				j++;
			else
				ft_error("Error\n", 3, pile_a);
		}
		j = 0;
	}
	return (0);
}

int	check_double(int *pile_a, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (size == 0)
		return (0);
	while (i < size)
	{
		while (j < size)
		{
			if (pile_a[i] == pile_a[j])
				ft_error("Error\n", 4, pile_a);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	*ft_parsing(int *pile_a, char **argv, int argc)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	j = 0;
	size = argc - 1;
	check_ifnumber(argv, argc, pile_a);
	while (i < argc)
	{
		pile_a[j] = ft_atoil(argv[i], pile_a);
		i++;
		j++;
	}
	check_double(pile_a, size);
	return (pile_a);
}
