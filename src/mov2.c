/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:22:07 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/12/20 16:19:53 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push *p, int flag)
{
	t_list	*aux;

	if (ft_lstsize(p->stack_a) < 2)
		return ;
	aux = p->stack_a;
	p->stack_a = p->stack_a->next;
	aux->next = NULL;
	ft_lstadd_back(&p->stack_a, aux);
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_push *p, int flag)
{
	t_list	*aux;

	if (ft_lstsize(p->stack_b) < 2)
		return ;
	aux = p->stack_b;
	p->stack_b = p->stack_b->next;
	aux->next = NULL;
	ft_lstadd_back(&p->stack_b, aux);
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_push *p, int flag)
{
	ra(p, 0);
	rb(p, 0);
	if (flag == 1)
		ft_printf("rr\n");
}
