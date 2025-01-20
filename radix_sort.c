/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:04:20 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/01/20 23:12:29 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stack	*find_min_radix(t_stack **stack)
{
	t_stack	*head;
	t_stack	*temp;
	int		flag;

	flag = 0;
	temp = NULL;
	head = *stack;
	while (head != NULL)
	{
		if (head->index == -1 && (flag == 0 || (temp->content > head->content)))
		{
			temp = head;
			flag = 1;
		}
		head = head->next;
	}
	return (temp);
}

void	assign_index(t_stack **stack)
{
	t_stack	*current;
	int		index;

	current = find_min_radix(stack);
	index = 0;
	while (current)
	{
		current->index = index++;
		current = find_min_radix(stack);
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = ft_stack_size(*stack_a);
	assign_index(stack_a);
	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (*stack_a && (((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b, false);
			else
				ra(stack_a, false);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, false);
		i++;
	}
}
