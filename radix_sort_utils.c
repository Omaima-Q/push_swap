/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:12:40 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/01/20 23:12:42 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int	max_bits;
	int	num_bits;
	int	num;

	max_bits = 0;
	while (stack)
	{
		num_bits = 0;
		num = stack->index;
		if (num < 0)
			num *= -1;
		while (num > 0)
		{
			num >>= 1;
			num_bits++;
		}
		if (num_bits > max_bits)
			max_bits = num_bits;
		stack = stack->next;
	}
	return (max_bits);
}
