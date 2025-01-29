/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:58:29 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/01/20 23:09:23 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(char *str, int *flag)
{
	unsigned int		i;
	int					sign;
	unsigned long int	number;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	if ((number > 2147483648 && sign == -1) || (number > 2147483647
			&& sign == 1))
	{
		*flag = 0;
		return (0);
	}
	return (number * sign);
}

/* this function same as atoi you just have to handle the max numbers and min numbers
2147483647 (INT_MAX) is the maximum value of a signed 32-bit integer.
2147483648 is INT_MIN (absolute value).
and flag will handle the overflow cases
If number exceeds the limits for its sign, it sets *flag = 0 to indicate an error and returns 0.*/

char	**parse_args(int arg_count, char **args)
{
	int		i;
	char	*arg;
	char	*tmp;
	char	**split;

	if (!arg_count || !args || !*args)
		return (ft_putstr_fd(ERROR_ARGS, 2), NULL);
	i = 1;
	if (!check_empty(args))
		return (ft_putstr_fd(ERROR_ARGS, 2), NULL);
	arg = ft_strjoin(args[i++], " ");
	while (args[i])
	{
		tmp = ft_strjoin(arg, args[i]);
		free(arg);
		arg = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	split = ft_split(arg, ' ');
	free(arg);
	check_input(split);
	return (split);
}

static int	is_valid_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (1);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	check_input(char **av)
{
	int	i;

	i = 0;
	if (av[0] == NULL)
		error_handle();
	while (av[i])
	{
		if (is_valid_number(av[i]))
		{
			free_str(av);
			error_handle();
		}
		i++;
	}
	return (1);
}

int	check_repetition(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->content == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
