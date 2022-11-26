/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:19:54 by eunson            #+#    #+#             */
/*   Updated: 2022/11/25 20:19:31 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_deque *deque, char c)
{
	int	tmp_data;

	tmp_data = deque->head->data;
	deque->head->data = deque->head->next->data;
	deque->head->next->data = tmp_data;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	each_swap(t_deque *deque_a, t_deque *deque_b)
{
	swap(deque_a, 'c');
	swap(deque_b, 'c');
	ft_putstr_fd("ss\n", 1);
}
