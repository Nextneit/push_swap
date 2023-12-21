/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:25:53 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/12/20 16:23:08 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push	*p;

	p = ft_calloc(1, sizeof(t_push));
	if (!p)
		return (EXIT_FAILURE);
	if (argc == 2)
		p->arg = ft_split(argv[1], ' ');
	else if (argc > 2)
		p->arg = argv + 1;
	else
		return (ft_printf("No hay argumentos\n"), EXIT_FAILURE);
	if (check_argv(p->arg) == 1)
		return (ft_printf("Argumento no valido\n"), EXIT_FAILURE);
	if (check_rep(p->arg) == 1)
		return (ft_printf("Argumentos repetidos\n"), EXIT_FAILURE);
	fill_a(p);
	get_index(p);
	if (check_index(p) == 0)
		return (ft_printf("Argumentos ordenados uwu\n"), EXIT_SUCCESS);
	ft_printf("stack_A\n");
	check_stack(p, p->stack_a);
	ft_printf("stack_A\n");
	check_stack(p, p->stack_a);
	ft_printf("stack_B\n");
	check_stack(p, p->stack_b);

}

void	check_stack(t_push *p, t_list *list)
{
	t_list	*aux;

	(void)p;
	aux = list;
	while (aux != NULL)
	{
		ft_printf("value->%d index->%d\n", aux->value, aux->index);
		aux = aux->next;
	}
	ft_printf("\n");

}
