/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:54:37 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/10/21 19:33:44 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_argv(char **arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i] != NULL)
	{
		while (arg[i][j] != '\0')
		{
			if (arg[i][j + 1] == '-' || arg[i][j + 1] == '+')
				return (EXIT_FAILURE);
			if (arg[i][j] == '-' || arg[i][j] == '+')
				j++;
			if (ft_isdigit(arg[i][j]))
				return (EXIT_FAILURE);
			j++;
		}
		if (ft_atol(arg[i]) < MIN_INT || ft_atol(arg[i]) > MAX_INT)
			return (EXIT_FAILURE);
		j = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_rep(char **arg)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	j = 0;
	f = 0;
	while (arg[i] != NULL)
	{
		while (arg[j] != NULL)
		{
			if (ft_atoi(arg[i]) == ft_atoi(arg[j]))
				f++;
			if (f > 1)
				return (EXIT_FAILURE);
			j++;
		}
		j = 0;
		f = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}
