/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:19:42 by eunson            #+#    #+#             */
/*   Updated: 2022/11/30 10:47:48 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_deque *deq_dst, t_deque *deq_src, char c)
{
	t_element	*prev_dst_head;
	t_element	*prev_src_head;

	if (deq_src->total_cnt == 0)
		return ;
	prev_dst_head = deq_dst->head;
	prev_src_head = deq_src->head;
	deq_src->head = deq_src->head->next;
	if (deq_src->head)
		deq_src->head->prev = 0;
	deq_dst->head = prev_src_head;
	deq_dst->head->next = prev_dst_head;
	if (prev_dst_head)
		prev_dst_head->prev = deq_dst->head;
	else
	{
		deq_dst->head->next = 0;
		deq_dst->tail = deq_dst->head;
	}
	deq_dst->total_cnt++;
	deq_src->total_cnt--;
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("pb\n", 1);
}
