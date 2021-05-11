#include "libswap.h"

void	ft_where_to_pb(t_list **head, t_data *data)
{
//	printf("ft_where to pb - start\n");
//	printf("\t\thead:\t%d\nnext che sara' pushato:\t%d\n", (*head)->num, (*head)->next->num);
//	if ((*data->b_head))
//		printf("\t\tb_head:\t%d\n", (*data->b_head)->num);
//	if (data->flag_both)
//	{
//		ft_rotate(head);
//		ft_rotate(data->b_head);
//		ft_write("rr \n");
//		data->flag_both = 0;
//	}
//	else
//	{
///	if ((*head)->next->num )
//	data->flag_both++;
		ft_rotate(head);
		ft_write("ra \n");
//	}
	data->ops++;
}

void	ft_move_wrong(t_list **head, t_data *data)
{ //int x = 0;
		

	if ((*head)->next->num > data->tail->num || (*head)->next->num == data->min)
	{
		//if ((*head)->num == data->max)
		//	return ;
		ft_swap(head);
		ft_write("sa \n");
		data->ops++;
	}
	else
	{
	//	printf("\t\tnext che sara' pushato:\t%d\n",  (*head)->next->num);
		if (!(*data->b_head) || ((*data->b_head) && (*head)->next->num > (*data->b_head)->num))
		{
			ft_rotate(head);
			ft_write("ra \n");
			data->ops++;
			if (!(*data->b_head))
				data->b_min = (*head)->num;
			else if ((*head)->num < data->b_min)
				data->b_min = (*head)->num;
			ft_push(head, data->b_head);
			ft_write("pb \n");
			data->ops++;
			
		}
		else
		{
		//	printf("\n");
//			printf("head: %d\tnext: %d\n", (*head)->num, (*head)->next->num);
//	if ((*data->b_head))
//		printf("b_head: %d\n", (*data->b_head)->num);
				
/*			ft_rotate(head);
			ft_rotate(data->b_head);
			ft_write("rr \n");
			data->ops++;
*/			
			ft_where_to_pb(head, data);
/*		printf("pre a:\n");
			ft_print_stack(head);
			printf("pre b:\n");
			ft_print_stack(data->b_head);
*/			
			/// il while lo devo mettere in una funzione:
			// ft_where_to_pb!! -> dentro va salvato su tmp il valore start
			// oppure controllare controllare senza mosse dove va inserito!!
	//		while ((*data->b_head) && (*data->b_head)->next && (*head)->num < (*data->b_head)->num)
	//		{
		//		printf("pre a:\n");
		//	ft_print_stack(head);
		//	printf("pre b:\n");
		//	ft_print_stack(data->b_head);
	//			ft_rotate(data->b_head);
	//			ft_write("rb \n");
	//			data->ops++;
	//		}
			if (!(*data->b_head))
				data->b_min = (*head)->num;
			else if ((*head)->num < data->b_min)
				data->b_min = (*head)->num;
			ft_push(head, data->b_head);
			ft_write("pb \n");
			data->ops++;
//			printf("post push su b:\n");
//			ft_print_stack(data->b_head);
//			printf("\n--\n");
		}
/*			printf("a:\n");
			ft_print_stack(head);
			printf("b:\n");
			ft_print_stack(data->b_head);
			//exit(0);
	*/}
}

t_list	*ft_get_tail(t_list **head, t_list *tail)
{
	tail = *head;
	while (tail->next)
		tail = tail->next;
	return (tail);
}

void	ft_check_if_pa(t_list **head, t_data *data)			// controllare se si puo inserire b_head durante ra!
{
	data->tail = ft_get_tail(head, data->tail);
	if (*data->b_head && (*data->b_head)->num > data->tail->num && (*data->b_head)->num < (*head)->num)
	{
		ft_push(data->b_head, head);
		ft_write("pa \n");
		data->ops++;
	}

}

int	ft_while_sorted(t_list **head, t_data *data)
{
	while ((*head)->num < (*head)->next->num)
	{
		ft_check_if_pa(head, data);
	/*	if (data->flag_both)
		{
			ft_rotate(head);
			ft_rotate(data->b_head);
			ft_write("rr \n");
			data->flag_both = 0;
			printf("post flag b:\n");
			ft_print_stack(data->b_head);
		}
		else
		{
	*/		ft_rotate(head);
			ft_write("ra \n");
	//	}
//		if ((*head)->num == data->min && ft_check_swap(head, data) == 1)
//			return (1);
	}
	return (0);
}