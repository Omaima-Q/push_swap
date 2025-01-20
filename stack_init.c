/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:04:49 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/01/20 23:09:49 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static t_stack	*find_last(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void	fill_stack(t_stack **a, int num)
{
	t_stack	*tmp;
	t_stack	*last_node;

	if (!a)
		return ;
	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return ;
	tmp->content = num;
	tmp->index = -1;
	tmp->next = NULL;
	if (!(*a))
	{
		*a = tmp;
		tmp->prev = NULL;
	}
	else
	{
		last_node = find_last(*a);
		last_node->next = tmp;
		tmp->prev = last_node;
	}
}

void	ft_init_stack(t_stack **a, char **str)
{
	int		i;
	long	num;
	int		flag;

	if (!str)
		return ;
	i = 0;
	flag = 1;
	while (str[i])
	{
		num = ft_atol(str[i], &flag);
		if (flag == 0)
			return (free_str(str), ft_stack_clear(a), error_handle());
		if (check_repetition(*a, (int)num))
			return (free_str(str), ft_stack_clear(a), error_handle());
		fill_stack(a, (int)num);
		i++;
	}
	free_str(str);
}
