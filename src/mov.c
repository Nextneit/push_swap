/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:48:50 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 12:34:48 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push *p, int flag)
{
	t_list	*aux;

	if (p->stack_b == NULL)
		return ;
	aux = p->stack_b;
	p->stack_b = aux->next;
	aux->next = NULL;
	ft_lstadd_front(&p->stack_a, aux);
	if (flag == 1)
		ft_printf("pa\n");
}

void	pb(t_push *p, int flag)
{
	t_list	*aux;

	if (p->stack_a == NULL)
		return ;
	aux = p->stack_a;
	p->stack_a = aux->next;
	aux->next = NULL;
	ft_lstadd_front(&p->stack_b, aux);
	if (flag == 1)
		ft_printf("pb\n");
}

void	sa(t_push *p, int flag)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(p->stack_a) < 2)
		return ;
	first = p->stack_a;
	second = p->stack_a->next;
	first->next = second->next;
	second->next = first;
	p->stack_a = second;
	if (flag == 1)
		ft_printf("sa\n");
}

void	sb(t_push *p, int flag)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(p->stack_b) < 2)
		return ;
	first = p->stack_b;
	second = p->stack_b->next;
	first->next = second->next;
	second->next = first;
	p->stack_b = second;
	if (flag == 1)
		ft_printf("sb\n");
}

void	ss(t_push *p, int flag)
{
	sa(p, 0);
	sb(p, 0);
	if (flag == 1)
		ft_printf("ss\n");
}
