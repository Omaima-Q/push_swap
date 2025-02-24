/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:12:20 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/01/20 23:12:23 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push1(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	(*src) = (*src)->next;
	temp->next = *dest;
	(*dest) = temp;
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push1(b, a);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push1(a, b);
	if (!print)
		write(1, "pb\n", 3);
}
