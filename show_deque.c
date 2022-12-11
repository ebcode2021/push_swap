#include "push_swap.h"

void	show_deque(t_deque *deque)
{
	t_element *element = deque->head;
	printf("head : %p\n", element);
	for (int i = 0; i < deque->total_cnt; i++)
	{
		printf("addr : %p | prev : %p | next : %p | data : %d\n", element, element->prev, element->next, element->data);
		element = element->next;
	}
	printf("tail : %p\n", deque->tail);
	printf("\n");
}
