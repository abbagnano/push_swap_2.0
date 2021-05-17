#include "libswap.h"

// ./push_swap 8895 3085 7585 2451 9634 2797 4207 1093 3191 2913


void	ft_sort_pushed(t_list **dst_head, t_data *data, int med, int *back)
{
//	printf("ft_sort_pushed - start.. b_stack\n");
//	printf("dst_head: %d\n", (*dst_head)->pos);
//	ft_print_stack(data->b_head);
	data->b_tail = ft_get_tail(dst_head, data->b_tail);
	if ((*dst_head)->next && (*dst_head)->next->pos > (*dst_head)->pos)//  && (*head)->next->pos != min_pos)
	{
		if ((*dst_head)->pos == med )//- *back)
		{
		//	printf("rotato su b: %d\n", (*dst_head)->pos);
			if (ft_rotate(dst_head))
			{
				//
				ft_write("rb \n");
				data->ops++;
				(*back)++;
				(*back)--;
			}
		}
		else if ((*dst_head)->pos > data->b_tail->pos)
		{
			//ft_print_stack(data->b_head);
			ft_swap(dst_head);
			ft_write("sb \n");
			data->ops++;
		}
		else
		{
		//	printf("rotato su b: %d\n", (*dst_head)->pos);
			if (ft_rotate(dst_head))
			{
				//printf("rotato su b: %d\n", (*dst_head)->pos);
				ft_write("rb \n");
				data->ops++;
				(*back)++;
				(*back)--;
			}
		}
	//	ft_push(head, dst_head);
	//	ft_write("pb \n");
	//	data->ops += 2;
	//	x++;
	}

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
//	printf("xxxxxx : %d\n", x);
	return (x);

}

void	ft_push_back(t_data *data)
{
	int y = 0;
	int x = 0;
	while (/*(*data->b_head)->pos > 0 && */(*data->b_head))//&& (*data->b_head)->pos < (*data->head)->pos)
	{
		if (!ft_check_pushed(data->head, data))
			x = ft_find_next_pa(data->b_head, (*data->head)->pos - 1);
		else
			x = ft_find_next_pa(data->b_head, (*data->head)->next->pos - 1);
		//printf("else break xxxxx : %d\n", x);
		///printf("xxxxxx\n");
		if ((*data->b_head)->pos < 0 && -(*data->b_head)->pos == (*data->head)->pos - 1)
				(*data->b_head)->pos *= -1;
		if (!ft_check_pushed(data->head, data) && (*data->b_head)->pos == (*data->head)->pos - 1)
		{
		//	printf("1\n");
			//if ((*data->b_head)->pos < 0)
			//	(*data->b_head)->pos *= -1;
			ft_push(data->b_head, data->head);
			ft_write("pa \n");
			data->ops++;
		}
		else if ((*data->b_head)->next && (*data->b_head)->next->pos > (*data->b_head)->pos && x < 3)// && (*data->b_head)->pos > 0) //x < 3)//(*data->b_head)->next->pos == (*data->head)->pos - 1)
		{
		//	printf("2\n");
		//printf("else break xxxxx : %d\n", x);
				//if ((*data->b_head)->pos < 0 && (*data->b_head)->next->pos)
				ft_swap(data->b_head);
				ft_write("sb \n");
				data->ops++;
			//	printf("post_sb\t a_head: %d\t b_head: %d\n", (*data->head)->pos , (*data->b_head)->pos);
		}
		else if (!ft_check_pushed(data->head, data) && (*data->b_head)->pos == (*data->head)->pos - 2 && x < 4)
		{
			
			//if (x > 3)
			//	continue ;
		//	printf("3\n");
			ft_push(data->b_head, data->head);
			ft_write("pa \n");
			data->ops++;
		}
	//	else if ((*data->b_head)->next && (*data->b_head)->next->pos > (*data->b_head)->pos)
	//	{
		//	printf("4\n");
	//			ft_swap(data->b_head);
	//			ft_write("sb4\n");
	//			data->ops++;
			//	printf("post_sb\t a_head: %d\t b_head: %d\n", (*data->head)->pos , (*data->b_head)->pos);
	//	}
		else if ((*data->b_head)->pos == (*data->head)->pos + 1)
		{
		//	printf("5\n");
			//if ((*data->b_head)->pos < 0)
			//	(*data->b_head)->pos *= -1;
			ft_push(data->b_head, data->head);
			ft_write("pa \n");
			data->ops++;
			ft_swap(data->head);
			ft_write("sa \n");
			data->ops++;
		}
		else if ((*data->head)->pos == (*data->head)->next->pos + 1 || (*data->head)->pos == -(*data->head)->next->pos + 1 )
		{
			if ((*data->head)->next->pos < 0)
				(*data->head)->next->pos *= -1;
			ft_swap(data->head);
			ft_write("sa \n");
			data->ops++;
		}
		else //if ((*data->b_head)->pos == (*data->head)->pos - 2)
		{
		//	return ;
			y++;
		//	if (y > 1)
		//		return ;
		//	printf("else half_back:\t\t\t\tY = %d\n", y);
			ft_halfing_back(data->b_head, data->head, data);
		//	return ;
		//	if (y > 1)
		//		return ;
			if (ft_check_pushed(data->head, data))
			{
			//	printf("else half_a_interval\n");
				ft_start_halfing_2(data->head, data->b_head, data);
			}
		//	if (y > 1)
		//		return ;
			//return ;
		}
	}

}

/*
void	ft_push_back(t_data *data)
{
	while ((*data->b_head) && (*data->b_head)->pos < (*data->head)->pos)
	{
		int x = ft_find_next_pa(data->b_head, (*data->head)->pos - 1);
		///printf("xxxxxx\n");
		if ((*data->b_head)->pos < 0 && -(*data->b_head)->pos == (*data->head)->pos - 1)
				(*data->b_head)->pos *= -1;
		else if ((*data->b_head)->pos == (*data->head)->pos - 1)
		{
			//if ((*data->b_head)->pos < 0)
			//	(*data->b_head)->pos *= -1;
			ft_push(data->b_head, data->head);
			ft_write("pa \n");
			data->ops++;
		}
	//	else //if ((*data->b_head)->pos == (*data->head)->pos - 2)
	//	{
			//printf("a_head: %d\t b_head: %d\n", (*data->head)->pos , (*data->b_head)->pos);
			
		//	printf("xxxxxx : %d\n", x);
		//	break ;
			else if (x == 2 && (*data->b_head)->next && (*data->b_head)->next->pos == (*data->head)->pos - 1)
			{
				ft_swap(data->b_head);
				ft_write("sb \n");
				data->ops++;
			//	printf("post_sb\t a_head: %d\t b_head: %d\n", (*data->head)->pos , (*data->b_head)->pos);
			}
			//else
			//{
				else if (!(*data->b_head)->next)
					return ;
				else if (!ft_check_pushed(data->head, data) && (*data->b_head)->pos == (*data->head)->pos - 2)
				{
					ft_push(data->b_head, data->head);
					ft_write("pa \n");
					data->ops++;
				}
				else if ((*data->b_head)->pos == (*data->head)->next->pos - 1)
				{	
					ft_push(data->b_head, data->head);
					ft_write("pa \n");
					data->ops++;
					ft_swap(data->head);
					ft_write("sa \n");
					data->ops++;
				}	
				else if ((*data->b_head)->next && (*data->b_head)->next->pos > (*data->b_head)->pos)
				{
					printf("aaaaaaaaaaaaaaa\n");
						ft_swap(data->b_head);
						ft_write("sb \n");
						data->ops++;
				}
				else if ((*data->b_head)->pos == (*data->head)->pos + 1)
				{
					ft_push(data->b_head, data->head);
					ft_write("pa \n");
					data->ops++;
					ft_swap(data->head);
					ft_write("sa \n");
					data->ops++;
				}
				else
				{
				printf("\nelse break a_head: %d\t b_head: %d\t", (*data->head)->pos , (*data->b_head)->pos);
				printf("b_head->next: %d\n", (*data->b_head)->next->pos);
				printf("else break xxxxx : %d\n", x);
			
				ft_halfing_back(data->b_head, data->head, data);
					printf("\n\n\tpost post a:\n");
			ft_print_stack(data->head);
				printf("\tpost post b:\n");
			ft_print_stack(data->b_head);
				printf("exit on push back\n");
				exit(0) ;
			}
		//	printf("a_head: %d\t b_head: %d\n", (*data->head)->pos , (*data->b_head)->pos);
		//	ft_push(data->b_head, data->head);
		//	ft_write("pa \n");
		//	data->ops++;
	//	}
	}

}
*/
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
//	printf("\t\t\t\tlen : %d\tmed: %d\n", len, med);
	if (!(len % 2))
		x++;
	while (x < len / 2 ) //&& ft_keep_swapping(head, data))
	{
		//if (len /2 == 12 && x == 11)
		//	return ;
		//if (!ft_keep_swapping(head, data))
		//	return ;
	//	printf("len : %d\tmed: %d\n", len, med);
		//printf("x: %d\t pos: %d\n", x, (*head)->pos);
	//	printf("len/2: %d\n", len /2);
		if ((*head) && (*head)->pos > med)
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
	//		printf("pushed: %d\n", (*head)->pos);
			ft_push(head, dst_head);
			ft_write("pa \n");
			data->ops++;
			x++;
		//	if (len /2 == 12 && x == 11)
		//	{
		//		printf("x: %d\t pos: %d\n", x, (*head)->pos);
		//		return ;
		//	}
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
		
/*		printf("back start: %d\n", back);
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
		printf("back end: %d\n", back);
*/	}
//printf("back start: %d\n", back);
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
//		printf("back end: %d\n", back);

//	printf("\tb:\n");
}

int	ft_check_pushed(t_list **head, t_data *data)
{
	t_list *tmp;

	tmp = *head;
	(void)data;
	while (tmp->next)
	{
		if (tmp->next && tmp->pos != tmp->next->pos - 1 )
		{
		//	printf("pos: %d\tnext->pos: %d\n",tmp->pos, tmp->next->pos  );
			if (tmp->next->pos < 0 && tmp->pos == -tmp->next->pos - 1)
				break ;
			else if (tmp->pos < 0 && tmp->pos == -tmp->next->pos - 1)
				break ;			
			return (1);
		}
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}

	return (0);
}

void	ft_halfing_back(t_list **head, t_list **dst_head, t_data *data)
{

//	printf("DOOHHH - HALFINGGG BACK\n");
	int len;
	int min_pos;

	len = ft_listlen(head, &min_pos);
//	printf("len: %d\tmin_pos: %d\n", len, min_pos);
		if (*dst_head)
			(*dst_head)->pos *= -1;
		ft_halfing_stack_rev(head, dst_head, min_pos, data);
		len = ft_listlen(head, &min_pos);
//	printf("ft_check_pushed: %d\n", ft_check_pushed(dst_head, data));

	return ;
/*
	if (ft_check_pushed(dst_head, data))
	{
//		printf("qwe\n");
//		printf("\n\n\ta:\n");
//ft_print_stack(data->head);
//printf("\tb:\n");
//ft_print_stack(data->b_head);
//printf("exit on  HALFINGGG BACK\n");
exit(0);

		ft_halfing_pushed(data->head, data);
		printf("qwend\n");
		printf("\n\n\tpost post a:\n");
			ft_print_stack(dst_head);
				printf("\tpost post b:\n");
			ft_print_stack(head);
	}*/
}

void	ft_sort_by_pos(t_data *data)
{
//printf("start mosse: %d\n", data->ops);
	if (!ft_keep_swapping(data->head, data))
	{
		if ((*data->head)->num != data->min)
		{
			ft_put_lower_at_head(data->head, data, 1);
//			printf("\n\n\tpost post a:\n");
		//	ft_print_stack(data->head);
		}
		return ;
		
	}
	ft_start_halfing(data->head, data->b_head, data);



ft_push_back(data);


//printf("\tpost a:\n");
//ft_print_stack(data->head);
//printf("\tpost b:\n");
//ft_print_stack(data->b_head);
	return ;

/*

	while (*data->b_head)// && ++loop < 500)
	{
		ft_push_back(data);
		printf("end mosse: %d\n", data->ops);
		exit(0) ;
	//printf("endind..head: %d\n", (*data->head)->pos);
		if ((*data->head)->pos == 1)
			break ;
//	(*data->head)->pos *= -1;
//ft_halfing_back(data->b_head, data->head, data);
		ft_what_next(data);
	//	ft_halfing_back(data->b_head, data->head, data);
	//	break ;
	}

printf("\n\n\tpost post a:\n");
ft_print_stack(data->head);
printf("\n\n\tpost post b:\n");
ft_print_stack(data->b_head);
*/

}