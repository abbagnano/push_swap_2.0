#include "libswap.h"

void	ft_halfing_stack(t_list **head, t_list **dst_head, int min_pos, t_data *data)
{
	int x;
	int med;
	int len;
	int back;


	x = 0;
	back = 0;
	len = ft_listlen(head, &min_pos);
	med = min_pos + len / 2;
//	printf("len : %d\tmed: %d\n", len, med);
	while (x < len / 2) 
	{
	/*	printf("\na_head: %d\n", (*head)->pos);
		printf("a_next: %d\n", (*head)->next->pos);
		if ((*dst_head))
			printf("\tb_head: %d\n",(*dst_head)->pos );
		if ((*dst_head) && (*dst_head)->next)
			printf("\tb_next: %d\n\n",(*dst_head)->next->pos );
	*/	if ((*head)->pos < med)
		{
			if ((*head)->next->pos < med && (*head)->next->pos < (*head)->pos && (*head)->next->pos > 0)
			{
				ft_swap(head);
				ft_write("sa \n");
				data->ops++;
			}
			ft_push(head, dst_head);
			ft_write("pb \n");
			data->ops++;
			x++;
			ft_sort_pushed(dst_head, data, med, &back);
		}
		else
		{
			if ((*head)->next->pos >= med && (*head)->next->pos < (*head)->pos)
			{
				ft_swap(head);
				ft_write("sa \n");
				data->ops++;
			}
			if (ft_rotate(head))
			{
				ft_write("ra \n");
				data->ops++;
			}
		}
	}
}

void	ft_halfing_stack_2(t_list **head, t_list **dst_head, int min_pos, t_data *data)
{
//	printf("start - halfing_stackkk222222\n");
	int x;
	int med;
	int len;
	int back;


	x = 0;
	back = 0;
	len = ft_listlen(head, &min_pos);
	med = min_pos + len / 2;
//	printf("len : %d\tmed: %d\n", len, med);
	while (x < len / 2) 
	{
	/*	printf("\na_head: %d\n", (*head)->pos);
		printf("a_next: %d\n", (*head)->next->pos);
		if ((*dst_head))
			printf("\tb_head: %d\n",(*dst_head)->pos );
		if ((*dst_head) && (*dst_head)->next)
			printf("\tb_next: %d\n\n",(*dst_head)->next->pos );
	*/	if ((*head)->pos < med)
		{
			if ((*head)->next->pos < med && (*head)->next->pos < (*head)->pos && (*head)->next->pos > 0)
			{
				ft_swap(head);
				ft_write("sa \n");
				data->ops++;
			}
			ft_push(head, dst_head);
			ft_write("pb \n");
			data->ops++;
			x++;
			ft_sort_pushed(dst_head, data, med, &back);
		}
		else
		{
			if ((*head)->next->pos >= med && (*head)->next->pos < (*head)->pos)
			{
				ft_swap(head);
				ft_write("sa \n");
				data->ops++;
			}
			if (ft_rotate(head))
			{
				ft_write("ra \n");
				data->ops++;
				back++;
			}
		}
	}
	
	while (back)
	{
		if (ft_rev_rot(head))
		{
			ft_write("rra");
			ft_write("\n");
			data->ops++;
			back--;
		}
	}
	

}

void	ft_start_halfing(t_list **head, t_list **dst_head, t_data *data)
{
//	printf("start - start halfing\n");
	int len;
	int min_pos;

	len = ft_listlen(head, &min_pos);
	while (len > 2 && ft_check_pushed(data->head, data))//ft_keep_swapping(data->head, data)) 
	{
		if (*dst_head)
			(*dst_head)->pos *= -1;
		ft_halfing_stack(head, dst_head, min_pos, data);
		len = ft_listlen(head, &min_pos);
	}
	if ((*data->head)->num != min_pos)
	{
		ft_put_lower_at_head(data->head, data, min_pos);
	}
}

void	ft_start_halfing_2(t_list **head, t_list **dst_head, t_data *data)
{
//	printf("start - start halfing222\n");
	int len;
	int min_pos;

	len = ft_listlen(head, &min_pos);
	//int med = min_pos + len / 2;
//	printf("len : %d\tmed: %d\n", len, med);
	while (len > 2 && ft_check_pushed(data->head, data))//ft_keep_swapping(data->head, data)) 
	{
		if (*dst_head)
			(*dst_head)->pos *= -1;
		ft_halfing_stack_2(head, dst_head, min_pos, data);
		len = ft_listlen(head, &min_pos);
	//	int med = min_pos + len / 2;
	//	printf("len : %d\tmed: %d\n", len, med);
	}
//	if ((*data->head)->num != min_pos)
//	{
//		ft_put_lower_at_head(data->head, data, min_pos);
//	}
}