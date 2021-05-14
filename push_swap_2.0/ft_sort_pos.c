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
		if (ft_find_lower(head, data, 1) < data->len/2)
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
	while (tmp && tmp->pos > 0)
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
//	printf("len: %d\n", len);
//	printf("min_pos: %d\n", min_pos);
	med = min_pos + len / 2;
//	printf("med: %d\n", med);
	while (x < len / 2) //&& ft_keep_swapping(head, data))
	{
		//if (!ft_keep_swapping(head, data))
		//	return ;
	//	printf("x: %d\t pos: %d\n", x, (*head)->pos);
		if ((*head)->pos < med)
		{
			if ((*head)->next->pos < med && (*head)->next->pos < (*head)->pos)//(*head)->next->pos == (*head)->pos - 1)// && (*head)->next->pos != min_pos)
			{
				ft_swap(head);
				ft_write("sa \n");
				data->ops++;
			//	ft_push(head, dst_head);
			//	ft_write("pb \n");
			//	data->ops += 2;
			//	x++;
			}
			ft_push(head, dst_head);
			ft_write("pb \n");
			data->ops++;
			x++;
			if ((*dst_head)->next && (*dst_head)->next->pos > (*dst_head)->pos)//  && (*head)->next->pos != min_pos)
			{
				ft_swap(dst_head);
				ft_write("sb \n");
				data->ops++;
			//	ft_push(head, dst_head);
			//	ft_write("pb \n");
			//	data->ops += 2;
			//	x++;
			}
		//	printf("\tb:\n");
		//	ft_print_stack(data->b_head);
		//	printf("x: %d\t pos: %d\n", x, (*head)->pos);
		//	exit(0);		
		}
		else
		{
			if ((*head)->next->pos >= med && (*head)->next->pos == (*head)->pos - 1)
			{
				ft_swap(head);
				ft_write("sa \n");
				data->ops++;
			//	ft_rotate(head);
			//	ft_write("ra \n");
			//	data->ops += 2;
			}
		//	else
		//	{
		//		printf("a_head: %d\t a_head->next: %d\n", (*data->head)->pos , (*data->head)->next->pos);
//
//			}
			if (ft_rotate(head))
			{
				ft_write("ra \n");
				data->ops++;
			}
		}
	}
}
/*
void	ft_sort_five(t_list **head, int min_pos)
{
	int len;

	len = ft_listlen(head, )
	while (!ft_check_local_sort(head, min_pos, min_pos))
}
*/
void	ft_start_halfing(t_list **head, t_list **dst_head, t_data *data)
{
	int len;
	int min_pos;

	len = ft_listlen(head, &min_pos);
//	printf("111 ft_keep_sw: %d\n", ft_keep_swapping(head, data));
//	printf("ft_loc_sort: %d\n", ft_check_local_sort(head, min_pos, min_pos + len));
//	return ;
//	min_pos = 0;
	while (len > 2 && ft_keep_swapping(data->head, data)) //(len > 6)
	{
	//	printf("DOOHHH\n");
		if (*dst_head)
			(*dst_head)->pos *= -1;
		ft_halfing_stack(head, dst_head, min_pos, data);
		len = ft_listlen(head, &min_pos);
	//	printf("len: %d\n", len);
//		printf("\n\n\twhile a:\n");
//	ft_print_stack(data->head);
//	printf("\twhile b:\n");
//	ft_print_stack(data->b_head);
	}
/*	printf("mosse: %d\n", data->ops);
	printf("\n\n\tpost a:\n");
	ft_print_stack(data->head);
	printf("\tpost b:\n");
	ft_print_stack(data->b_head);
*///	printf("ft_keep_sw: %d\n", ft_keep_swapping(head, data));
//printf("qwasdasde\n");
	if (/*!ft_keep_swapping(data->head, data) && */(*data->head)->num != min_pos)
	{
		ft_put_lower_at_head(data->head, data, min_pos);
//		printf("qwe\n");
	}
	
	//ft_sort_five(head);
}

int ft_find_next_pa(t_list **head, int next)
{
	t_list *tmp;
	int x;

	x = 0;
	tmp = *head;
	while (++x && tmp)
	{
		if (tmp->pos < 0 && -tmp->pos == next)
			return (x);
		else if (tmp->pos == next)
			return (x);
		tmp = tmp->next;
	}
//	while (++x && tmp->pos != next)
//		tmp = tmp->next;
	printf("xxxxxx : %d\n", x);
	return (x);

}

void	ft_push_back(t_data *data)
{
	while (/*(*data->b_head)->pos > 0 && */(*data->b_head) && (*data->b_head)->pos < (*data->head)->pos)
	{
		///printf("xxxxxx\n");
		if ((*data->b_head)->pos < 0 && -(*data->b_head)->pos == (*data->head)->pos - 1)
				(*data->b_head)->pos *= -1;
		if ((*data->b_head)->pos == (*data->head)->pos - 1)
		{
			//if ((*data->b_head)->pos < 0)
			//	(*data->b_head)->pos *= -1;
			ft_push(data->b_head, data->head);
			ft_write("pa \n");
			data->ops++;
		}
		else //if ((*data->b_head)->pos == (*data->head)->pos - 2)
		{
			//printf("a_head: %d\t b_head: %d\n", (*data->head)->pos , (*data->b_head)->pos);
			int x = ft_find_next_pa(data->b_head, (*data->head)->pos - 1);
		//	printf("xxxxxx : %d\n", x);
		//	break ;
			if (x == 2 && (*data->b_head)->next && (*data->b_head)->next->pos == (*data->head)->pos - 1)
			{
				ft_swap(data->b_head);
				ft_write("sb \n");
				data->ops++;
			//	printf("post_sb\t a_head: %d\t b_head: %d\n", (*data->head)->pos , (*data->b_head)->pos);
			}
			else
			{
				if (!(*data->b_head)->next)
					return ;
				printf("\nelse break a_head: %d\t b_head: %d\t", (*data->head)->pos , (*data->b_head)->pos);
				printf("b_head->next: %d\n", (*data->b_head)->next->pos);
				printf("else break xxxxx : %d\n", x);
				break ;
			}
		//	printf("a_head: %d\t b_head: %d\n", (*data->head)->pos , (*data->b_head)->pos);
		//	ft_push(data->b_head, data->head);
		//	ft_write("pa \n");
		//	data->ops++;
		}
	}

}

void	ft_halfing_stack_rev(t_list **head, t_list **dst_head, int min_pos, t_data *data)
{
	int x;
	int med;
	int len;
	int	back;


	x = 0;
	back = 0;
	len = ft_listlen(head, &min_pos);
	med = min_pos + len / 2;
	printf("len : %d\tmed: %d\n", len, med);
	while (x < len / 2 ) //&& ft_keep_swapping(head, data))
	{
		//if (!ft_keep_swapping(head, data))
		//	return ;
		printf("x: %d\t pos: %d\n", x, (*head)->pos);
		printf("len/2: %d\n", len /2);
		if ((*head) && (*head)->pos >= med)
		{
			if ((*head)->next && (*head)->next->pos > med && (*head)->next->pos > (*head)->pos)//(*head)->next->pos == (*head)->pos - 1)// && (*head)->next->pos != min_pos)
			{
				ft_swap(head);
				ft_write("sb \n");
				data->ops++;
			//	ft_push(head, dst_head);
			//	ft_write("pb \n");
			//	data->ops += 2;
			//	x++;
			}
			ft_push(head, dst_head);
			ft_write("pa \n");
			data->ops++;
			x++;
			if ((*dst_head)->next && (*dst_head)->next->pos > 0 && (*dst_head)->next->pos < (*dst_head)->pos)//  && (*head)->next->pos != min_pos)
			{
				ft_swap(dst_head);
				ft_write("sa \n");
				data->ops++;
			//	ft_push(head, dst_head);
			//	ft_write("pb \n");
			//	data->ops += 2;
			//	x++;
			}
		//	printf("\tb:\n");
		//	ft_print_stack(data->b_head);
		//	printf("x: %d\t pos: %d\n", x, (*head)->pos);
		//	exit(0);		
		}
		else
		{
			if ((*head)->next && (*head)->next->pos <= med && ((*head)->next->pos == (*head)->pos + 1 ))//|| -(*head)->next->pos == (*head)->pos + 1))
			{
				ft_swap(head);
				ft_write("sb \n");
				data->ops++;
			//	ft_rotate(head);
			//	ft_write("ra \n");
			//	data->ops += 2;
			}
		//	else
		//	{
		//		printf("a_head: %d\t a_head->next: %d\n", (*data->head)->pos , (*data->head)->next->pos);
//
//			}
			if (ft_rotate(head))
			{
				ft_write("rb \n");
				data->ops++;
				back++;
			}
		}
	}
	while (back)
	{
		if (ft_rev_rot(head))
			{
				ft_write("rrb");
				ft_write("\n");
				data->ops++;
				back--;
			}
	}

//	printf("\tb:\n");
}

void	ft_halfing_back(t_list **head, t_list **dst_head, t_data *data)
{

	printf("DOOHHH - HALFINGGG BACK\n");
	int len;
	int min_pos;

	len = ft_listlen(head, &min_pos);
//	printf("111 ft_keep_sw: %d\n", ft_keep_swapping(head, data));
//	printf("ft_loc_sort: %d\n", ft_check_local_sort(head, min_pos, min_pos + len));
	printf("len: %d\tmin_pos: %d\n", len, min_pos);
//	return ;
//	while (len > 2 && ft_check_local_sort(dst_head, min_pos, min_pos + len)) //ft_keep_swapping(data->head, data)) //(len > 6)
//	{
		//printf("DOOHHH\n");
		if (*dst_head)
			(*dst_head)->pos *= -1;
		ft_halfing_stack_rev(head, dst_head, min_pos, data);
		len = ft_listlen(head, &min_pos);
	//	printf("len: %d\n", len);
//		printf("\n\n\twhile a:\n");
//	ft_print_stack(data->head);
//	printf("\twhile b:\n");
//	ft_print_stack(data->b_head);
//	}
	//printf("DOOHHH\n");
	printf("mosse: %d\n", data->ops);
	printf("\n\n\tpost a:\n");
	ft_print_stack(data->head);
	printf("\tpost b:\n");
	ft_print_stack(data->b_head);
//	exit(0);
//return ;
//	printf("ft_keep_sw: %d\n", ft_keep_swapping(head, data));
//printf("qwasdasde\n");
//	if (/*!ft_keep_swapping(data->head, data) && */(*data->head)->num != min_pos)
//	{
//		ft_put_lower_at_head(data->head, data, min_pos);
//		printf("qwe\n");
//	}
}

void	ft_sort_by_pos(t_data *data)
{
/*printf("\n\n\ta:\n");
ft_print_stack(data->head);
printf("\tb:\n");
ft_print_stack(data->b_head);
*/
//printf("ft_keep_sw: %d\n", ft_keep_swapping(data->head, data));
//printf("min: %d\n", data->min);
printf("start mosse: %d\n", data->ops);
	// divido A finche non ho 2 o 3 num e li sorto!!
	if (!ft_keep_swapping(data->head, data))
	{
		if ((*data->head)->num != data->min)
		{
			ft_put_lower_at_head(data->head, data, 1);
			printf("\n\n\tpost post a:\n");
			ft_print_stack(data->head);
		}
		return ;
		
	}
	ft_start_halfing(data->head, data->b_head, data);

	while (*data->b_head)
	{
	//	printf("endind..head: %d\n", (*data->head)->pos);
		ft_push_back(data);
	//printf("endind..head: %d\n", (*data->head)->pos);
		if ((*data->head)->pos == 1)
			break ;
//	(*data->head)->pos *= -1;

		ft_halfing_back(data->b_head, data->head, data);
	}

//	ft_new_sort(data->head, data);
//printf("end mosse: %d\n", data->ops);
//printf("\n\n\tpost a:\n");
//ft_print_stack(data->head);
//printf("\tpost b:\n");
//ft_print_stack(data->b_head);



printf("\n\n\tpost post a:\n");
ft_print_stack(data->head);
printf("\n\n\tpost post b:\n");
ft_print_stack(data->b_head);

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