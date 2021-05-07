#include "libswap.h"

//https://visualgo.net/en/sorting?slide=8

void	ft_put_lower_at_head(t_list **head, t_data *data)
{
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
}

int	ft_nearest_wrong(t_list **head, t_data *data)
{
	t_list *tmp;
	int		x;

	tmp = *head;
	x = 0;
	if (tmp->num == data->max)
		return (0);
	while (tmp->next && tmp->num < tmp->next->num)
	{
		x++;
		tmp = tmp->next;
	}
	//printf("%d\n", x);
	return (x);
}

void	ft_find_med(t_list **head, t_data *data)
{
	data->ops = 0;
	int w;
	while (!(ft_check_swap(head, data)))
	{
		w = ft_nearest_wrong(head, data);
		if (w < data->len / 2)
		{
			while ((*head)->num < (*head)->next->num)
			{
				ft_rotate(head);
				ft_write("ra \n");
				data->ops++;
				if ((*head)->num == data->min && ft_check_swap(head, data) == 1)
					return ;
			}
				
	//		if ((*head)->num < (*head)->next->num)
	//		{
				ft_swap(head);
				ft_write("sa \n");
				data->ops++;
	//		}
		}
		else
		{	
			while ((*head)->num > (*head)->next->num)
			{
				ft_rev_rot(head);
				ft_write("rra");
				ft_write("\n");
				data->ops++;
				if ((*head)->num == data->min && ft_check_swap(head, data))
					return ;
			}
	//		if ((*head)->num < (*head)->next->num)
	//		{
							
				ft_swap(head);
				ft_write("sa \n");
				data->ops++;
	//		}

		}
		if (ft_keep_swapping(head, data))// && printf("keep_swap\n"))
			continue ;
		ft_put_lower_at_head(head, data);	
	}
	
}

/*
void	ft_find_med(t_list **head, t_data *data)
{
	t_list	*tmp;
	t_list	**azz;

	tmp = *head;
	azz = &tmp;
	//ft_print_stack(&tmp);
	while (!(ft_check_swap(azz, data)))
	{		
	//	while (tmp->next)
	//	{
			while  (tmp->next->next && tmp->num < tmp->next->num)
				tmp = tmp->next;
				//ft_rotate(azz);
			ft_swap(&tmp);
		//	ft_rotate(azz);
			//tmp = tmp->next;
	//	}
	//	tmp = *head;
			while (tmp->num != data->min)
				tmp = tmp->next;
//				ft_rotate(azz);
	}
	printf("tmp:\n");
	ft_print_stack(azz);

	
}*/
/*
int	ft_comp_sort(t_data *data)
{
	int data->ops;
	int	tail = 0;

	data->ops = 0;
	while (!(ft_check_swap(data->head, data)))
	{
		
*/


	/*	if (data->len > 4 && (*data->head)->next->num == data->max && (*data->head)->num == data->min)
		{
			ft_swap(data->head);
			ft_write("sa \n");
			ft_rotate(data->head);
			ft_write("ra \n");
			data->ops += 2;
		}
		while ((*data->head)->next && (*data->head)->num < (*data->head)->next->num)
		{
			ft_rotate(data->head);
			ft_write("ra \n");
			data->ops++;
			if (data->len > 3 && (*data->head)->next->num == data->min) 
			{
				ft_rotate(data->head);
				ft_write("ra \n");
				data->ops++;
			}
		}
		ft_swap(data->head);
		ft_write("sa \n");
		data->ops++;
		if (ft_keep_swapping(data->head, data))
			continue ;
		if (ft_find_lower(data->head, data) < data->len/2)
		{
			while ((*data->head)->num != data->min)
			{
				ft_rotate(data->head);
				ft_write("ra \n");
				data->ops++;
			}
		}
		else
		{
			while ((*data->head)->num != data->min)
			{
				ft_rev_rot(data->head);
				ft_write("rra");
				ft_write("\n");
				data->ops++;
			}
		}
	*/	