/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:25:53 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/01/02 14:47:54 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_leaks(void)
{
	system("leaks -q push_swap");
}

void	del_content(int content)
{
	content = 0;
}

static void	initialize_struct(t_push *p)
{
	p->arg = NULL;
	p->stack_a = NULL;
	p->stack_b = NULL;
	p->a = NULL;
	p->b = NULL;
	p->aux = NULL;
	p->aux2 = NULL;
}

int	main2(t_push *p)
{
	fill_a(p);
	get_index(p);
	if (check_index(p) == 0)
		return (EXIT_SUCCESS);
	if (ft_lstsize(p->stack_a) == 2)
		return (sa(p, 1), EXIT_SUCCESS);
	if (ft_lstsize(p->stack_a) == 3)
		return (sort_3(p), EXIT_SUCCESS);
	push_b(p);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_push	*p;
	char	**split;

	atexit(ft_leaks);
	p = ft_calloc(1, sizeof(t_push));
	if (!p)
		return (EXIT_FAILURE);
	initialize_struct(p);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		p->arg = split;
	}
	else if (argc > 2)
		p->arg = argv + 1;
	else
		return (free(p), ft_printf("Error a\n"), EXIT_FAILURE);
	if (check_argv(p->arg) == 1)
		return (free_arg(split), free(p), ft_printf("Error b\n"), EXIT_FAILURE);
	if (check_rep(p->arg) == 1)
		return (free_arg(split), free(p), ft_printf("Error c\n"), EXIT_FAILURE);
	main2(p);
	return (ft_lstclear(&p->stack_a, &del_content),
		ft_lstclear(&p->stack_b, &del_content),
		free(p), free_arg(split), EXIT_SUCCESS);
}
