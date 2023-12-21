/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:02:59 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/12/19 12:17:08 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int value, int index, int pos, int target_pos)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->value = value;
	new_list->index = index;
	new_list->pos = pos;
	new_list->target_pos = target_pos;
	new_list->cost_a = 0;
	new_list->cost_b = 0;
	new_list->next = NULL;
	return (new_list);
}
