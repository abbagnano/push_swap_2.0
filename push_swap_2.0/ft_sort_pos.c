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
		//	printf("x: %d\n", x);
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

	while (x < data->len)
	{
		if ((*data->head)->pos < data->len / 2)
		{			
			ft_push(data->head, data->b_head);
			ft_write("pb \n");
			data->ops++;
		}
		else
		{
			ft_rotate(data->head);
			ft_write("ra \n");
			data->ops++;
		}
		x++;
	}
/*	printf("\n\n\tpost a:\n");
			ft_print_stack(data->head);
			printf("\tpost b:\n");
			ft_print_stack(data->b_head);
*/
}


void	ft_sort_pos(t_data *data)
{

//	printf("ft_sort_pos - start\t ops: %d\tlen: %d\n", data->ops, data->len);
	ft_print_stack(data->head);
	printf("\nft_divido_stack - start\t ops: %d\tlen: %d\n", data->ops, data->len);
	ft_divido_stack(data);
	printf("ft_bubble_sort - start\t ops: %d\tlen: %d\n", data->ops, data->len);
	ft_bubble_sort(data->head, data);
//	ft_rev_bubble_sort(data->b_head, data);
//	ft_merge_stack(data);
	
}