/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:42:55 by eunson            #+#    #+#             */
/*   Updated: 2022/11/30 10:49:42 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assert_duplicate(t_element *head, int data)
{
	t_element	*tmp_element;

	tmp_element = head;
	while (tmp_element)
	{
		if (tmp_element->data == data)
			exit_error();
		tmp_element = tmp_element->next;
	}
}

int	sort_check(t_element *element)
{
	if (element)
		element = element->next;
	while (element)
	{
		if (element->data < element->prev->data)
			return (0);
		element = element->next;
	}
	return (1);
}
