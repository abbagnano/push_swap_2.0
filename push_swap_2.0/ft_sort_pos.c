#include "libswap.h"

// ./push_swap 8895 3085 7585 2451 9634 2797 4207 1093 3191 2913

int	ft_check_local_sort(t_list **head, int min, int max)
{
	t_list *tmp;

	tmp = *head;
	while (tmp->next)
	{
		if (tmp->pos == max && tmp->next->pos == min)
			tmp = tmp->next;
		if (tmp->next && tmp->pos > tmp->next->pos) 
			return (1);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	if (tmp->pos != max && tmp->pos > (*head)->pos)
		return (1);
	return (0);
}

int	ft_bubble_sort(t_list **head, t_data *data)
{
	int x;

	x = 1;
	while (x)
	{
		if ((*head)->next->pos == data->len && (*head)->pos == data->len / 2)
		{
			ft_swap(head);
			ft_write("sa \n");
			ft_rotate(head);
			ft_write("ra \n");
			data->ops += 2;
		}
		while ((*head)->next && (*head)->pos < (*head)->next->pos)
		{
			ft_rotate(head);
			ft_write("ra \n");
			data->ops++;
			if (/*data->len > 3 &&*/ (*head)->next->pos == data->len / 2)
			{
				ft_rotate(head);
				ft_write("ra \n");
				data->ops++;
			}
		//	x = ft_check_local_sort(head, data->len / 2, data->len);
		}
		ft_swap(head);
		ft_write("sa \n");
		data->ops++;
		x = ft_check_local_sort(head, data->len / 2, data->len);

//		printf("\n\n\twhile bubble a:\n");
//	ft_print_stack(data->head);
	}
	printf("\n\n\tpost bubble a:\n");
	ft_print_stack(data->head);
	printf("ops: %d\n", data->ops);
	exit (0);
//		if (ft_keep_swapping(head, data))
//			continue ;
		if (ft_find_lower(head, data) < data->len/2)
		{
			while ((*head)->num != data->min) //data->lowest->num)
			{
			//	ft_print_stack(head);
				ft_rotate(head);
				ft_write("ra \n");
				data->ops++;
			//	printf("rot\n");
			}
		}
		else
		{
			while ((*head)->num != data->min) //data->lowest->num)
			{
			//	ft_print_stack(head);
				ft_rev_rot(head);
				ft_write("rra");
				ft_write("\n");
				data->ops++;
			//	printf("rev_rot\n");
			}
		}
		
	
	ft_write("\n");
	printf("data->ops: %d\n", data->ops);
	
	return (data->ops);
}

void	ft_divido_stack(t_data *data)
{

	int x = 0;
	
	while (x < data->len / 2 - 1) //data->len)
	{
		if ((*data->head)->pos < data->len / 2)
		{			
			ft_push(data->head, data->b_head);
			ft_write("pb \n");
			data->ops++;
			x++;
		}
		else
		{
			ft_rotate(data->head);
			ft_write("ra \n");
			data->ops++;
		}
		// x++;
	}
/*	printf("\n\n\tpost a:\n");
			ft_print_stack(data->head);
			printf("\tpost b:\n");
			ft_print_stack(data->b_head);
*/
}

void	ft_move_wrong_2(t_list **head, t_data *data)
{
	//	per il sort si deve verificare: tail->num < num < next->num
	//	wrong: num > (next->num)   => next->num sta nella pos sbagliata	
	//	se next->num > tail->num allora faccio lo swap									(1)
	//	else controllo next->pos rispetto alla mediana... 
	//		se next->pos > data->len /2 allora ra e pb => lo metto in cima a B			(2)
		//		in cima cosi ft_check_if_pa piu immediato
	//		se next->pos < data->len /2 allora ra e pb e rrb => lo metto in fond a B	(3)

	if ((*head)->next->num > data->tail->num)// || ((*head)->next->num == data->min && (*head)->num != data->max))		//	(1)
	{
		if (ft_swap(head))
		{
			ft_write("sa \n");
			data->ops++;
		}
	}
	else if ((*head)->next->num == data->min)// && (*head)->num == data->max)
	{
		if (ft_rotate(head))
		{
			ft_write("ra \n");
			data->ops++;
		}
	//	if (ft_rotate(head))
	//	{
	//		ft_write("ra \n");
	//		data->ops++;
	//	}
		return ;
	}
	else		//	faccio subito ra per mettere il wrong come head e vedere che push fare
	{
		if (ft_rotate(head))
		{
			ft_write("ra \n");
			data->ops++;
		}
		//if ((*head)->next->num == data->min && (*head)->num != data->max)
		//	return ;
		if ((*head)->pos > data->len / 2)			//	(2) 
		{
			ft_push(head, data->b_head);
			ft_write("pb \n");
			data->ops++;
		}
		else													// (3)
		{
			ft_push(head, data->b_head);
			ft_write("pb \n");
			data->ops++;
			if (ft_rev_rot(data->b_head))
			{
				ft_write("rrb");
				ft_write("\n");
				data->ops++;
			}
		}
	}



}

void	ft_divido_sort(t_data *data)
{
	int last;

	data->tail = ft_get_tail(data->head, data->tail);
	last = data->tail->num;
	while  (/*(*data->head)->num != last) */ft_keep_swapping(data->head, data))
	{
			printf("\n\n\twhile a:\n");
			ft_print_stack(data->head);
			printf("\twhile b:\n");
			ft_print_stack(data->b_head);	
		ft_while_sorted(data->head, data);
		data->tail = ft_get_tail(data->head, data->tail);
		ft_move_wrong_2(data->head, data);
	//	data->tail = ft_get_tail(data->head, data->tail);
		
	//	if (data->tail->num == last)
	//	{
		//	printf("dooh.. %d\n", last );
			
	//		break ;
	//	}
		
	}
//	ft_empty_b(data->head, data);
//	if (ft_rotate(data->head))
//			{
//				ft_write("ra \n");
//				data->ops++;
//			}

	/*		printf("\n\n\tpost a:\n");
			ft_print_stack(data->head);
			printf("\tpost b:\n");
			ft_print_stack(data->b_head);
*/
}

int	ft_listlen(t_list **head, int *min_pos)
{
	int x;
	t_list *tmp;

	tmp = *head;
	x = 0;
	*min_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->pos < *min_pos)
			*min_pos = tmp->pos;
		tmp = tmp->next;
		x++;
	}
	return (x);
}

void	ft_halfing_stack(t_list **head, t_list **dst_head, int min_pos, t_data *data)
{
	int x;
	int med;
	int len;


	x = 0;
	len = ft_listlen(head, &min_pos);
	printf("len: %d\n", len);
	printf("min_pos: %d\n", min_pos);
	med = min_pos + len / 2;
	printf("med: %d\n", med);
	while (x < len / 2 )
	{
//		printf("x: %d\t pos: %d\n", x, (*head)->pos);
		if ((*head)->pos < med)
		{
			x++;
			ft_push(head, dst_head);
			ft_write("pb \n");
			data->ops++;
		//	printf("\tb:\n");
		//	ft_print_stack(data->b_head);
		//	printf("x: %d\t pos: %d\n", x, (*head)->pos);
		//	exit(0);		
		}
		else
		{
			if (ft_rotate(head))
			{
				ft_write("ra \n");
				data->ops++;
			}
		}
	}
}

void	ft_sort_five(t_list **head, int min_pos)
{
	int len;

	len = ft_listlen(head, )
	while (!ft_check_local_sort(head, min_pos, min_pos))
}

void	ft_start_halfing(t_list **head, t_list **dst_head, t_data *data)
{
	int len;
	int min_pos;

	len = ft_listlen(head, &min_pos);
//	min_pos = 0;
	while (len > 6)
	{
	//	printf("DOOHHH\n");
		ft_halfing_stack(head, dst_head, min_pos, data);
		len = ft_listlen(head, &min_pos);
		printf("len: %d\n", len);
	
	}
	printf("mosse: %d\n", data->ops);
	printf("\n\n\tpost a:\n");
	ft_print_stack(data->head);
	
	
	ft_sort_five(head);
}



void	ft_sort_by_pos(t_data *data)
{
printf("\n\n\ta:\n");
ft_print_stack(data->head);
printf("\tb:\n");
ft_print_stack(data->b_head);

//printf("start mosse: %d\n", data->ops);
	// divido A finche non ho 2 o 3 num e li sorto!!
	ft_start_halfing(data->head, data->b_head, data);
	
//	ft_new_sort(data->head, data);
//printf("end mosse: %d\n", data->ops);
//printf("\n\n\tpost a:\n");
//ft_print_stack(data->head);
//printf("\tpost b:\n");
//ft_print_stack(data->b_head);



printf("\n\n\tpost post a:\n");
ft_print_stack(data->head);

//exit(0);

//		second_try...

//	ft_divido_stack(data);
//		printf("\n\n\tpost a:\n");
//			ft_print_stack(data->head);
//			printf("\tpost b:\n");
//			ft_print_stack(data->b_head);
//ft_bubble_sort(data->head, data);
	
//	ft_divido_sort(data);

//	ft_empty_b(data->head, data);
	
			

/*		first_try...

//	printf("ft_sort_pos - start\t ops: %d\tlen: %d\n", data->ops, data->len);
	ft_print_stack(data->head);
	printf("\nft_divido_stack - start\t ops: %d\tlen: %d\n", data->ops, data->len);
	ft_divido_stack(data);
	printf("ft_bubble_sort - start\t ops: %d\tlen: %d\n", data->ops, data->len);
	ft_bubble_sort(data->head, data);
//	ft_rev_bubble_sort(data->b_head, data);
//	ft_merge_stack(data);
*/	
}