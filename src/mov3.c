/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:35:32 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 12:34:55 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push *p, int flag)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(p->stack_a) < 2)
		return ;
	aux = p->stack_a;
	last = ft_lstlast(p->stack_a);
	while (aux)
	{
		if (aux->next->next == NULL)
		{
			aux->next = NULL;
			break ;
		}
		aux = aux->next;
	}
	ft_lstadd_front(&p->stack_a, last);
	if (flag == 1)
		ft_printf("rra\n");
}

void	rrb(t_push *p, int flag)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(p->stack_b) < 2)
		return ;
	aux = p->stack_b;
	last = ft_lstlast(p->stack_b);
	while (aux)
	{
		if (aux->next->next == NULL)
		{
			aux->next = NULL;
			break ;
		}
		aux = aux->next;
	}
	ft_lstadd_front(&p->stack_b, last);
	if (flag == 1)
		ft_printf("rrb\n");
}

void	rrr(t_push *p, int flag)
{
	rra(p, 0);
	rrb(p, 0);
	if (flag == 1)
		ft_printf("rrr\n");
}
