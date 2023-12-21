/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:15:56 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/12/20 16:20:07 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "../libft/libft.h"
# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_push
{
	char	**arg;
	t_list	*stack_a;
	t_list	*stack_b;
}				t_push;

int				check_argv(char **arg);
int				check_rep(char **arg);
int				fill_a(t_push *p);
long long int	ft_atol(char *s);
void			get_index(t_push *p);
void			check_stack(t_push *p, t_list *list);
int				check_index(t_push *p);
void			pa(t_push *p, int flag);
void			pb(t_push *p, int flag);
void			sa(t_push *p, int flag);
void			sb(t_push *p, int flag);
void			ss(t_push *p, int flag);
void			ra(t_push *p, int flag);
void			rb(t_push *p, int flag);
void			rr(t_push *p, int flag);

#endif