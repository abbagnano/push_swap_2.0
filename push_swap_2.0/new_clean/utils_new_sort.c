#include "libswap.h"


t_list	*ft_get_tail(t_list **head, t_list *tail)
{
	tail = *head;
//	printf("\n\n\tpost a:\n");
//	ft_print_stack(head);
	while (tail->next) //&& printf("dooh.. \n"))
		tail = tail->next;
	return (tail);
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


void	ft_init_pos(t_list **head)
{
	t_list *tmp;

	tmp = *head;
	while (tmp)
	{
		tmp->pos = 1;
		tmp = tmp->next;
	}
}

void	ft_check_pos(t_data *data, int num)
{
	t_list *tmp;

	tmp = *data->head;
	while (tmp)
	{
		if (tmp->num > num)
		{
			tmp->pos++;
		}
		tmp = tmp->next;
	}
}

void	ft_get_range(t_data *data)
{

	t_list *tmp;


	tmp = *data->head;
	data->len = 0;

	data->min = tmp->num;
	data->max = tmp->num;


	ft_init_pos(data->head);
	while (tmp)
	{
		if (tmp->num > data->max)//data->maxest->num)
		{
			data->max = tmp->num;
		}
		else if (tmp->num < data->min) //data->lowest->num)
		{
			data->min = tmp->num;

		}

		ft_check_pos(data, tmp->num);
		tmp = tmp->next;
		data->len++;
	}

}

int ft_find_lower(t_list **head, t_data *data, int min)
{
//	ft_print_stack(data->head);
	(void)data;
	t_list *tmp;
	int x;

	tmp = *head;
	x = 0;
	while (tmp && tmp->pos != min)
	{
		tmp = tmp->next;
		x++;
	}
//	ft_print_stack(data->head);
//	printf("len: %d\t min_pos: %d\n", data->len, x);
	return (x);
}

void	ft_put_lower_at_head(t_list **head, t_data *data, int min)
{
	if (ft_find_lower(head, data, min) <= data->len/2)
	{
		while ((*head)->pos != min) //data->lowest->num)
		{
		//	ft_print_stack(head);
		//	ft_check_if_pa(head, data);
			if (ft_rotate(head))
			{
				ft_write("ra \n");
				data->ops++;
			}
		//	ft_check_if_pa(head, data);
		//	printf("rot\n");
		}
	}
	else
	{
		while ((*head)->pos != min) //data->lowest->num)
		{
		//	ft_print_stack(head);
		//ft_check_if_pa(head, data);
			if(ft_rev_rot(head))
			{
				ft_write("rra");
				ft_write("\n");
				data->ops++;
			}
		//	ft_check_if_pa(head, data);

		//	printf("rev_rot\n");
		}
	}
}

