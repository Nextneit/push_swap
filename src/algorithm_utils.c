/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:37:46 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/12/21 16:49:05 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_push *p)
{
	t_list	*aux;

	aux = p->stack_a;
	if (aux->value < aux->next->value
		&& aux->next->value > aux->next->next->value)
	{
		rra(p, 1);
		aux = p->stack_a;
		if (aux->value > aux->next->value)
			sa(p, 1);
	}
	else if (aux->value > aux->next->value
		&& aux->value > aux->next->next->value)
	{
		ra(p, 1);
		aux = p->stack_a;
		if (aux->value > aux->next->value)
			sa(p, 1);
	}
	else if (aux->value > aux->next->value
		&& aux->value < aux->next->next->value)
		sa(p, 1);
}

void	put_pos(t_push *p)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = p->stack_b;
	while (++i <= ft_lstsize(p->stack_b))
	{
		aux->pos = i;
		aux = aux->next;
	}
	aux = p->stack_a;
	i = 0;
	while (++i <= ft_lstsize(p->stack_a))
	{
		aux->pos = i;
		aux = aux->next;
	}
}

void	put_t_pos(t_push *p)
{
	
}
