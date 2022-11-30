/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:34:40 by eunson            #+#    #+#             */
/*   Updated: 2022/11/30 10:56:13 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	push_swap_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*(str + 1) < '0' || *(str + 1) > '9')
			exit_error();
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			exit_error();
		num = num * 10 + (*str - '0');
		if (num * sign < -2147483648 || num * sign > 2147483647)
			exit_error();
		str++;
	}
	return ((int)num * sign);
}

void	element_add_back(t_deque *deque, t_element *element)
{
	t_element	*tmp_element;

	if (!(deque->head))
	{
		deque->head = element;
		deque->tail = element;
		element->prev = 0;
		element->next = 0;
	}
	else
	{
		assert_duplicate(deque->head, element->data);
		tmp_element = last_element(deque->head);
		tmp_element->next = element;
		deque->tail = element;
		deque->tail->prev = tmp_element;
		deque->tail->next = 0;
	}
}

t_element	*last_element(t_element *head)
{
	t_element	*tmp_element;

	tmp_element = head;
	while (tmp_element->next)
		tmp_element = tmp_element->next;
	return (tmp_element);
}
