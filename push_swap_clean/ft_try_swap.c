#include "libswap.h"

void	ft_get_range(t_data *data)
{
//	int min;
//	int max;
	t_list *tmp;

//	data->lowest = (t_list *)malloc(sizeof(t_list ) * 1);
//	data->maxest = (t_list *)malloc(sizeof(t_list ) * 1);
//	data->start = (t_list *)malloc(sizeof(t_list *) * 1);
//	data->tail = (t_list *)malloc(sizeof(t_list *) * 1);
//	data->start = *data->head;
	tmp = *data->head;
	data->len = 0;
//	data->lowest->num = tmp->num;
//	data->maxest->num = tmp->num;
	data->min = tmp->num;
	data->max = tmp->num;
//	data->med = 0;
//	data->zxc = 0;
	while (tmp)
	{
		if (tmp->num > data->max)//data->maxest->num)
		{
			data->max = tmp->num;
//			data->maxest = tmp;
		}
		else if (tmp->num < data->min) //data->lowest->num)
		{
			data->min = tmp->num;
			
//			data->lowest = tmp;
		}
//		if (!tmp->next)
//			data->tail = tmp;
//		data->zxc = (data->zxc + tmp->num) / 2;
//		data->med += tmp->num;
		//tmp->pos = 1;
		tmp = tmp->next;
		data->len++;
	}
//	data->med = data->med / data->len;
//	data->qwe = (data->min + data->max) / 2;
	//tmp = *data->head;
	//while (tmp && tmp->num != data->min)
	//	tmp = tmp->next;
	//*data->lowest = tmp;
//	printf("min: %d\t max: %d \n", data->min, data->max);
//	printf("data-minest: %d\t data-maxest: %d \nstart->num: %d\ttail-num: %d\n", (data->lowest)->num, (data->maxest)->num, data->start->num, data->tail->num);
//	printf("med.%lld\n", data->med);
//	printf("zxc.%lld\n", data->zxc);
//	printf("qwe.%lld\n", data->qwe);

//	exit(0);
}



int		ft_first_try(t_data *data)
{
//	t_list *tmp_head;
	

	
	data->ops = 0;
	while (!(ft_check_swap(data->head, data)))// && (*data->b_head))
	{
	//	printf("\n\n\n\tSTART\n");
	//		ft_print_stack(data->head);
	//	ft_print_stack(data->b_head);
		while ((*data->head)->next && (*data->head)->num < (*data->head)->next->num)
		{
		//	printf("\n\tloop 1 finche num < next->num\n");
			
			//ft_print_stack(data->head);
	//		printf("1loop headnum: %d\n", (*data->head)->num );
		//	if ((*data->b_head) && (*data->b_head)->num < (*data->head)->num)
		//	{	
		//		ft_push(data->b_head, data->head);
		//		data->ops++;
			//	ft_print_stack(data->head);
		//	}
			ft_rotate(data->head);//data->head = data->head->next;
			data->ops++;
			if ((*data->head)->next->num == data->min) //data->lowest->num)
			{
				ft_rotate(data->head);//data->head = data->head->next;
				data->ops++;
			}
		}
	//	printf("before pb: headnum: %d\n", (*data->head)->num );
	//	if ((*data->head)->num != data->maxest->num)
	//	{
	//		ft_push(data->head, data->b_head);
	//		data->ops++;
	//	}	
	//	else
	//	{
			ft_swap(data->head);
			data->ops++;
	//	}
	//	if ((*data->b_head) && (*data->b_head)->num < (*data->head)->num)
	//	{
	//		ft_push(data->b_head, data->head);
	//		data->ops++;
		//	ft_print_stack(data->head);
	//	}
		while ((*data->head)->num != data->min) //data->lowest->num)
		{
	//		printf("\n\truoto la lista finche non mmetto il lowest alla head\n");
	//		printf("headnum: %d\n", (*data->head)->num );
	//		printf("\n\tFINE\n");
		//	if ((*data->b_head) && (*data->b_head)->num < (*data->head)->num)
		//	{
		//		ft_push(data->b_head, data->head);
		//		data->ops++;
			//	ft_print_stack(data->head);
		//	}
			ft_rotate(data->head);
			data->ops++;
		}
	}
//	printf("\n\tFINE\n");

//	ft_print_stack(data->head);

//	ft_swap(data->head);
//	tmp_head = *data->head;
//	tmp_head = data->start;
//	printf("\n\tSTART\n");
//	printf("data-minest: %d\n", data->lowest->num);
//	ft_print_stack(&tmp_head);
//	ft_rotate(&tmp_head);
//	ft_rotate(data->head);
//	ft_push(data->head, data->b_head);
//	ft_rev_rot(data->head);

/*
	while (!(ft_check_swap(data->head, data)))
	{
	//	printf("\n\tFINE\n");
		//tmp_head = data->start;
		while ((*data->head)->next/ && (*data->head)->num < (*data->head)->next->num)
		{
			printf("\n\tloop 1 finche num < next->num\n");
		//	if ((*data->head)->next->num == data->lowest->num)
		//		break ;
			ft_rotate(data->head);//data->head = data->head->next;
			data->ops++;
		}
		ft_print_stack(data->head);
		if ((*data->head)->num > (*data->head)->next->num && /(*data->head)->next->num != data->lowest->num && /(*data->head)->num != data->maxest->num)
		{
			printf("\n\tse num > next->num fa swap\n");
		//	if ((*data->head)->next->num == data->lowest->num)
			//	break ;
			ft_swap(data->head);
			data->ops++;
		}
		ft_print_stack(data->head);
	//	printf("data-minest: %d\n", data->lowest->num);
		while ((*data->head)->num != //data->start->num) // data->lowest->num)
		{
			printf("\n\truoto la lista finche non mmetto il lowest alla head\n");
	//		printf("headnum: %d\n", (*data->head)->num );
	//		printf("\n\tFINE\n");
			ft_rotate(data->head);
			data->ops++;
		}
		ft_print_stack(data->head);
	}
*/
//	ft_swap(&tmp->next);
/*	while (tmp && !(ft_check_swap(&tmp, data)))
	{
		if (tmp->num < tmp->next->num)
		{
			ft_swap(&tmp);
			data->ops++;
			printf("\n\t\tswappato\n");
			ft_print_stack(&tmp);
		}
		//else
		//{
			ft_rotate(&tmp);
			printf("\n\t\trotato\n");
			ft_print_stack(&tmp);
		//}	
	}
*/
//	printf("\n\tFINE\n");
//printf("data-minest: %d\n", data->lowest->num);
//	ft_print_stack(&tmp);
	return (data->ops);
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
		
		if (tmp->num > tmp->next->num) 
		{
			if (tmp->num == data->max && tmp->next->num == data->min)
				return (0);
			return (1);
		}
		tmp = tmp->next;
	}
//	printf("head: %d\tnum: tmp: %d\n", (*head)->num, tmp->num);
//	if (tmp->num > (*head)->num && (*head)->num != data->min && tmp->num != data->max)
//		return (1);
//	printf("qwe\n");
	return (0);
}

int	ft_second_try(t_data *data)
{
//	printf("ft_second\n");
//	ft_print_stack(data->head);
//	ft_print_stack(data->backup);
	

	data->ops = 0;
	while (!(ft_check_swap(data->head, data)) )// && (*data->b_head))
	{
	//	printf("data->ops: %d\n", data->ops);
		while ((*data->head)->next && (*data->head)->num < (*data->head)->next->num )
		{
			ft_rotate(data->head);//data->head = data->head->next;
			data->ops++;
			if ((*data->head)->next->num == data->min) //data->lowest->num)
			{
				ft_rotate(data->head);//data->head = data->head->next;
				data->ops++;
			}
		}
		ft_swap(data->head);
		data->ops++;
		if (ft_keep_swapping(data->head, data))
			continue ;
		while ((*data->head)->num != data->min) //data->lowest->num)
		{
			
			ft_rotate(data->head);
			data->ops++;
		}
	}
//		printf("ending - ft_second\n");
//	ft_print_stack(data->head);
//	ft_print_stack(data->backup);
	return (data->ops);
}

int ft_find_lower(t_list **head, t_data *data)
{
//	ft_print_stack(data->head);
	t_list *tmp;
	int x;

	tmp = *head;
	x = 0;
	while (tmp && tmp->num != data->min)
	{
		tmp = tmp->next;
		x++;
	}
//	ft_print_stack(data->head);
//	printf("len: %d\t min_pos: %d\n", data->len, x);
	return (x);
}

int	ft_third_try(t_data *data)
{
	

	data->ops = 0;
	while (!(ft_check_swap(data->head, data)))// && (*data->b_head))
	{
		if (data->len > 4 && (*data->head)->next->num == data->max && (*data->head)->num == data->min)
		{
			ft_swap(data->head);
			ft_write("sa \n");
			ft_rotate(data->head);
			ft_write("ra \n");
			data->ops += 2;
		}
		while ((*data->head)->next && (*data->head)->num < (*data->head)->next->num)
		{
			ft_rotate(data->head);//data->head = data->head->next;
			ft_write("ra \n");
			data->ops++;
			if (data->len > 3 && (*data->head)->next->num == data->min) //data->lowest->num)
			{
				ft_rotate(data->head);//data->head = data->head->next;
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
			while ((*data->head)->num != data->min) //data->lowest->num)
			{
			//	ft_print_stack(data->head);
				ft_rotate(data->head);
				ft_write("ra \n");
				data->ops++;
			//	printf("rot\n");
			}
		}
		else
		{
			while ((*data->head)->num != data->min) //data->lowest->num)
			{
			//	ft_print_stack(data->head);
				ft_rev_rot(data->head);
				ft_write("rra");
				ft_write("\n");
				data->ops++;
			//	printf("rev_rot\n");
			}
		}
		
	}
	ft_write("\n");
	printf("data->ops: %d\n", data->ops);
	
	return (data->ops);
}

void	ft_backup_list(t_list **empty, t_list **head, t_data *data)
{
	t_list *tmp;

	tmp = *head;
	*empty = NULL;
	while(tmp != NULL)
	{
	//	printf("qwe\n");
		ft_add_num(tmp->num, empty, data);
		tmp = tmp->next;
	}
	tmp = NULL;
//	data->backup = empty;
//ft_print_stack(empty);
}

void	ft_restore_list(t_list **dst, t_list **src)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *src;
	new = *dst;
//	new = NULL;
		printf("qwe\n");
	while(tmp)
	{
	//	printf("qwe\n");
		new->num = tmp->num;
		new->next = tmp->next;
		tmp = tmp->next;
		new = new->next;
	}
	new = NULL;
	printf("endqwe\n");
//	new->next = NULL;
//	printf("qwe\n");
//	tmp = *dst;
//	while(tmp)
//	{
//		printf("%d\n", tmp->num);
//		tmp = tmp->next;
//	}
//	printf("qwe\n");
//ft_print_stack(dst);
}

void	ft_push_swap(t_data *data)
{
//	if (data->len < 10)
		ft_third_try(data);
//	else
//		ft_comp_sort(data);
}
/*
void	ft_push_swap____first(t_data *data)
{
	//	printf("data-minest: %d \t data-maxest: %d \ttail-num: %d\n", (data->lowest)->num, (data->maxest)->num, data->tail->num);
	int	a;
	int b;
	int c;

//	t_list **backup;
	//backup = NULL;
	data->backup = (t_list **)malloc(sizeof(t_list *) * 1);
	*data->backup = NULL;
//	printf("\n\npre backup\n");
//	ft_print_stack(data->backup);
//	ft_print_stack(data->head);
	ft_backup_list(data->backup, data->head, data);
//	printf("\n\npost backup\n");
//	ft_print_stack(data->backup);
//	ft_print_stack(data->head);
//	ft_rev_rot(data->head);
//	ft_rotate(data->head);
//	ft_print_stack(data->head);
//	return ;
//	printf("qwe\n");
//	data->backup = data->head;
//	printf("\n\npre sort\n");
//	ft_print_stack(data->backup);
//	ft_print_stack(data->head);
	a = ft_first_try(data);
//	a = ft_first_try(data->backup);
	printf("\n\t\ta mosse: %d\n", a);
	ft_print_stack(data->head);
	ft_free_stack(data->head);
	ft_backup_list(data->head, data->backup, data);
//	return ;
//	printf("\npre data = &data->backup;\n");
//	ft_print_stack(data->backup);
//	ft_print_stack(data->head);
//	printf("\n\npost sort\n");
//	ft_print_stack(data->backup);
//	ft_print_stack(data->head);
//	ft_restore_list(data->head, data->backup);   
//	printf("\n\npost restore & pre 2nd sort\n");
//	ft_print_stack(data->backup);
//	ft_print_stack(data->head);
//	return ;
//	data->head = data->backup;					
//	ft_data->backup_list(data->backup, data->head, data);
//	printf("\n\n1qwe\n");
//		ft_print_stack(data->backup);
//	printf("\npost data = &data->backup;\n");
//	ft_print_stack(data->head);
	b = ft_second_try(data);
	printf("\n\t\tb mosse: %d\n", b);
	ft_print_stack(data->head);
	ft_free_stack(data->head);
	ft_backup_list(data->head, data->backup, data);
//	ft_print_stack(data->head);
//	data->head = data->backup;
//	ft_data->backup_list(data->backup, data->head, data);
//	printf("\n\npost second sort\n");
//	ft_print_stack(data->backup);
//	ft_print_stack(data->head);
//	ft_restore_list(data->head, data->backup);
//	printf("\n\npost 2nd restore\n");
//	ft_print_stack(data->backup);
//	ft_print_stack(data->head);
	c = ft_third_try(data);
	printf("\n\t\tc mosse: %d\n", c);
	ft_print_stack(data->head);
	
}*/