/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:44:14 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/01/02 14:17:24 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	last_step(t_push *p)
{
	int		mid;
	t_list	*aux;

	mid = (ft_lstsize(p->stack_a) / 2) + 1;
	aux = p->stack_a;
	if (p->stack_a->index >= mid)
	{
		while (aux->index != 1)
		{
			ra(p, 1);
			aux = p->stack_a;
		}
	}
	else
	{
		while (aux->index != 1)
		{
			rra(p, 1);
			aux = p->stack_a;
		}
	}
}

void	push_b(t_push *p)
{
	while (ft_lstsize(p->stack_a) > 3)
		pb(p, 1);
	sort_3(p);
	while (p->stack_b != NULL)
	{
		put_pos(p);
		put_t_pos(p);
		put_costa(p);
		put_costb(p);
		p->aux = cheaper_cost(p);
		final_moves(p);
	}
	while (check_order(p) != 0)
		last_step(p);
}
