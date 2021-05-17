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
			data->len--;
			
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
			data->len--;
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
//	printf("\n\n\tpost a:\n");
//	ft_print_stack(head);
	while (tail->next) //&& printf("dooh.. \n"))
		tail = tail->next;
	return (tail);
}

void	ft_check_if_pa(t_list **head, t_data *data)			// controllare se si puo inserire b_head durante ra!
{
	int x = 0;
	data->tail = ft_get_tail(head, data->tail);
	if (*data->b_head && (*data->b_head)->num > data->tail->num && (*data->b_head)->num < (*head)->num)
	{
		ft_push(data->b_head, head);
		ft_write("pa \n");
		data->ops++;
		x++;
		//data->len++;
	}
	if (x)
		ft_check_if_pa(head, data);

}

int	ft_keep_swapping(t_list **head, t_data *data)
{
	t_list *tmp;

	tmp = *head;
	(void)data;
//	if ((*data->b_head))
//		return (1);
//	if ((*head)->num != data->min && tmp->num > (*head)->num)
//		return (1);
	while (tmp->next)
	{
	//	printf("%d\t%d\n",tmp->num, tmp->next->num  );
	//	if (tmp->next->num != data->min && tmp->num > tmp->next->num) 
	//	{
		//	printf("\n%d\t%d\n",tmp->num, tmp->next->num  );
		//	ft_print_stack(&tmp);
	//		return (1);
	//	}
	//	ft_check_if_pa(head, data);
		if (tmp->num == data->max && tmp->next->num == data->min)
			tmp = tmp->next;
		if (tmp->next && tmp->num > tmp->next->num) 
		{
			
			return (1);
		}
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	if (tmp->num != data->max && tmp->num > (*head)->num)
		return (1);
//	printf("head: %d\tnum: tmp: %d\n", (*head)->num, tmp->num);
//	if (tmp->num > (*head)->num && (*head)->num != data->min && tmp->num != data->max)
//		return (1);
//	printf("qwe\n");
	return (0);
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
	*/		if (ft_rotate(head))
			{
				ft_write("ra \n");
				data->ops++;
			}
	//	}
//		if ((*head)->num == data->min && ft_check_swap(head, data) == 1)
//			return (1);
	}
	return (0);
}