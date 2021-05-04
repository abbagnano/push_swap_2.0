#include "libswap.h"

void	ft_get_range(t_data *data)
{
//	int min;
//	int max;
	t_list *tmp;

	data->lowest = (t_list *)malloc(sizeof(t_list ) * 1);
	data->maxest = (t_list *)malloc(sizeof(t_list ) * 1);
	data->start = (t_list *)malloc(sizeof(t_list *) * 1);
	data->tail = (t_list *)malloc(sizeof(t_list *) * 1);
	data->start = *data->head;
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

void	ft_init_flags(t_flags *flags)
{
	flags->s = 0;
	flags->r = 0;
	flags->p = 0;
}

void	ft_parse_flags(t_data *data, t_flags *flags)
{
	if (flags->s > flags->r && flags->s > flags->p)
		ft_rotate(data->head);
	else if (flags->r > flags->r && flags->s > flags->p)
		ft_rotate(data->head);
}

void	ft_push_swap(t_data *data)
{
	printf("data-minest: %d\t data-maxest: %d \nstart->num: %d\ttail-num: %d\n", (data->lowest)->num, (data->maxest)->num, data->start->num, data->tail->num);
	t_list *tmp;
	t_flags flags;

	tmp = *data->head;
	ft_init_flags(&flags);
//	while (!(ft_check_swap(data)))
	{
		printf("\nxxxx\n");
		//	faccio check del primo num con il next	->	sa
		flags.s = tmp->num - tmp->next->num;
		printf("sa=num-next: %d\n", flags.s);
	//	ft_num_next(tmp->num, tmp->next->num, data, &flags);
		//	si fa il check del primo con l'ultimo	->	ra
		flags.r = tmp->num - data->tail->num;
		printf("ra=num-last: %d\n", flags.r);
	//	ft_num_last(tmp->num, data->tail->num, data, &flags);
		//	si fa il check con il primo sull-altro stack ->	pa
		if (*data->b_head)
		{
			flags.p = tmp->num - (*data->b_head)->num;
			printf("pa=num-bnum: %d\n", flags.p);
	//	ft_num_bnum(tmp->num, (*data->b_head)->num, data, &flags);
		}
	//	ft_parse_flags(data, &flags);
		return ;
	}
}
/*	
	while (tmp->next != NULL)
	{//printf("\nxxxx\n");
		while (tmp && tmp->num < tmp->next->num)
		{
			ft_rotate(data->head);
			tmp = *data->head;
			//tmp = tmp->next;
		}
		if (tmp && tmp->num > tmp->next->num)
		{
			ft_swap(data->head);
			tmp = *data->first;
		}
		//ft_push(data->b_head, data->head);
	}
}*/