/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:37:46 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/10/21 19:25:09 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	t_list	*aux;

	p->b = p->stack_b;
	while (p->b != NULL)
	{
		p->a = p->stack_a;
		aux = NULL;
		p->aux2 = NULL;
		while (p->a != NULL)
		{
			if (p->b->value < p->a->value
				&& (aux == NULL || aux->value > p->a->value))
				aux = p->a;
			if (p->aux2 == NULL || p->a->value > p->aux2->value)
				p->aux2 = p->a;
			p->a = p->a->next;
		}
		if (aux == NULL && check_order(p) == 0)
			p->b->target_pos = 1;
		else if (aux == NULL && check_order(p) == 1)
			p->b->target_pos = p->aux2->pos + 1;
		else
			p->b->target_pos = aux->pos;
		p->b = p->b->next;
	}
}

void	put_costb(t_push *p)
{
	int		size;
	int		mid;
	t_list	*aux;

	size = ft_lstsize(p->stack_b);
	aux = p->stack_b;
	mid = size / 2 + 1;
	while (aux != NULL)
	{
		if (aux->pos <= mid)
			aux->cost_b = aux->pos - 1;
		else
			aux->cost_b = (size - aux->pos + 1) * -1;
		aux = aux->next;
	}
}

void	put_costa(t_push *p)
{
	int		size;
	int		mid;
	t_list	*aux;

	size = ft_lstsize(p->stack_a);
	aux = p->stack_b;
	mid = size / 2 + 1;
	while (aux != NULL)
	{
		if (aux->target_pos <= mid)
			aux->cost_a = aux->target_pos - 1;
		else
			aux->cost_a = (size - aux->target_pos + 1) * -1;
		aux = aux->next;
	}
}
