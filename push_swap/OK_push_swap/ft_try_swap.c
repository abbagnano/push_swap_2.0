#include "libswap.h"

void	ft_get_range(t_data *data)
{
//	int min;
//	int max;
	t_list *tmp;

	data->lowest = (t_list *)malloc(sizeof(t_list ) * 1);
	data->maxest = (t_list *)malloc(sizeof(t_list ) * 1);
//	data->start = (t_list *)malloc(sizeof(t_list *) * 1);
	data->tail = (t_list *)malloc(sizeof(t_list *) * 1);
//	data->start = *data->head;
	tmp = *data->head;
	data->lowest->num = tmp->num;
	data->maxest->num = tmp->num;
	while (tmp)
	{
		if (tmp->num > data->maxest->num)
		{
//			data->max = tmp->num;
			data->maxest = tmp;
		}
		else if (tmp->num < data->lowest->num)
		{
//			data->min = tmp->num;
			data->lowest = tmp;
		}
		if (!tmp->next)
			data->tail = tmp;
		tmp = tmp->next;
	}
	//tmp = *data->head;
	//while (tmp && tmp->num != data->min)
	//	tmp = tmp->next;
	//*data->lowest = tmp;
//	printf("min: %d\t max: %d \n", data->min, data->max);
//	printf("data-minest: %d\t data-maxest: %d \nstart->num: %d\ttail-num: %d\n", (data->lowest)->num, (data->maxest)->num, data->start->num, data->tail->num);
}



int		ft_first_try(t_data *data)
{
//	t_list *tmp_head;
	int ops;

	
	ops = 0;
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
		//		ops++;
			//	ft_print_stack(data->head);
		//	}
			ft_rotate(data->head);//data->head = data->head->next;
			ops++;
			if ((*data->head)->next->num == data->lowest->num)
			{
				ft_rotate(data->head);//data->head = data->head->next;
				ops++;
			}
		}
	//	printf("before pb: headnum: %d\n", (*data->head)->num );
	//	if ((*data->head)->num != data->maxest->num)
	//	{
	//		ft_push(data->head, data->b_head);
	//		ops++;
	//	}	
	//	else
	//	{
			ft_swap(data->head);
			ops++;
	//	}
	//	if ((*data->b_head) && (*data->b_head)->num < (*data->head)->num)
	//	{
	//		ft_push(data->b_head, data->head);
	//		ops++;
		//	ft_print_stack(data->head);
	//	}
		while ((*data->head)->num != data->lowest->num)
		{
	//		printf("\n\truoto la lista finche non mmetto il lowest alla head\n");
	//		printf("headnum: %d\n", (*data->head)->num );
	//		printf("\n\tFINE\n");
		//	if ((*data->b_head) && (*data->b_head)->num < (*data->head)->num)
		//	{
		//		ft_push(data->b_head, data->head);
		//		ops++;
			//	ft_print_stack(data->head);
		//	}
			ft_rotate(data->head);
			ops++;
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
			ops++;
		}
		ft_print_stack(data->head);
		if ((*data->head)->num > (*data->head)->next->num && /(*data->head)->next->num != data->lowest->num && /(*data->head)->num != data->maxest->num)
		{
			printf("\n\tse num > next->num fa swap\n");
		//	if ((*data->head)->next->num == data->lowest->num)
			//	break ;
			ft_swap(data->head);
			ops++;
		}
		ft_print_stack(data->head);
	//	printf("data-minest: %d\n", data->lowest->num);
		while ((*data->head)->num != //data->start->num) // data->lowest->num)
		{
			printf("\n\truoto la lista finche non mmetto il lowest alla head\n");
	//		printf("headnum: %d\n", (*data->head)->num );
	//		printf("\n\tFINE\n");
			ft_rotate(data->head);
			ops++;
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
			ops++;
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
	return (ops);
}

int	ft_keep_swapping(t_list **head, t_data *data)
{
	t_list *tmp;

	tmp = *head;
	while (tmp->next)
	{
	//	printf("%d\t%d\n",tmp->num, tmp->next->num  );
		if (/*tmp->next->num &&*/ tmp->next->num != data->lowest->num && tmp->num > tmp->next->num)
		{
			printf("\n%d\t%d\n",tmp->num, tmp->next->num  );
			ft_print_stack(&tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	printf("qwe\n");
	return (0);
}

int	ft_second_try(t_data *data)
{
	//ft_print_stack(data->head);
	int ops;

	ops = 0;
	while (!(ft_check_swap(data->head, data)) )// && (*data->b_head))
	{
		printf("ops: %d\n", ops);
		while ((*data->head)->next && (*data->head)->num < (*data->head)->next->num )
		{
			ft_rotate(data->head);//data->head = data->head->next;
			ops++;
			if ((*data->head)->next->num == data->lowest->num)
			{
				ft_rotate(data->head);//data->head = data->head->next;
				ops++;
			}
		}
		ft_swap(data->head);
		ops++;
		if (ft_keep_swapping(data->head, data))
			continue ;
		while ((*data->head)->num != data->lowest->num)
		{
			
			ft_rotate(data->head);
			ops++;
		}
	}
	return (ops);
}

int	ft_third_try(t_data *data)
{
	int ops;

	ops = 0;
	while (!(ft_check_swap(data->head, data)))// && (*data->b_head))
	{
		while ((*data->head)->next && (*data->head)->num < (*data->head)->next->num)
		{
			ft_rotate(data->head);//data->head = data->head->next;
			ops++;
			if ((*data->head)->next->num == data->lowest->num)
			{
				ft_rotate(data->head);//data->head = data->head->next;
				ops++;
			}
		}
		ft_swap(data->head);
		ops++;
		if (ft_keep_swapping(data->head, data))
			continue ;
		while ((*data->head)->num != data->lowest->num)
		{
			ft_rotate(data->head);
			ops++;
		}
	}
	return (ops);
}

void	ft_backup_list(t_list **empty, t_list **head, t_data *data)
{
	t_list *tmp;

	tmp = *head;
	*empty = NULL;
	while(tmp)
	{
	//	printf("qwe\n");
		ft_add_num(tmp->num, empty, data);
		tmp = tmp->next;
	}
	data->backup = empty;
//ft_print_stack(empty);
}

void	ft_restore_list(t_list **dst, t_list **src)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *src;
	new = *dst;
	while(tmp)
	{
		//printf("qwe\n");
		new->num = tmp->num;
		new->next = tmp->next;
		tmp = tmp->next;
		new = new->next;
	}
	new = NULL;
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
		printf("data-minest: %d \t data-maxest: %d \ttail-num: %d\n", (data->lowest)->num, (data->maxest)->num, data->tail->num);
	int	a;
	int b;
	int c;

	t_list **backup;
	//backup = NULL;
	backup = (t_list **)malloc(sizeof(t_list *) * 1);
	*backup = NULL;	
	ft_backup_list(backup, data->head, data);
//	printf("qwe\n");
//	backup = data->head;
	a = ft_first_try(data);
//	a = ft_first_try(backup);
	printf("\n\t\ta mosse: %d\n", a);
//	printf("\npre data = &backup;\n");
//	ft_print_stack(backup);
//	ft_print_stack(data->head);
	ft_restore_list(data->head, backup);     /// con il restore_list sul secondtry va in loop
//	data->head = backup;					/// con data->head = backup il secondtry va ok!!
//	ft_backup_list(backup, data->head, data);
//	printf("\n\n1qwe\n");
//		ft_print_stack(backup);
//	printf("\npost data = &backup;\n");
//	ft_print_stack(data->head);
	b = ft_second_try(data);
	printf("\n\t\tb mosse: %d\n", b);
//	ft_print_stack(data->head);
//	data->head = backup;
//	ft_backup_list(backup, data->head, data);
	ft_restore_list(data->head, backup);
//	printf("\n\n2qwe\n");
//	ft_print_stack(backup);
	c = ft_third_try(data);
	printf("\n\t\tc mosse: %d\n", c);
//	ft_print_stack(data->head);
	
}