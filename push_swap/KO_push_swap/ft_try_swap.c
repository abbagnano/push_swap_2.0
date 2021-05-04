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

int		ft_single(t_data *data)
{
//	t_list *tmp_head;
	int ops;

	
	ops = 0;
//	tmp_head = *data->head;
//	tmp_head = data->start;
//	printf("\n\tSTART\n");
//	printf("data-minest: %d\n", data->lowest->num);
//	ft_print_stack(&tmp_head);
//	ft_rotate(&tmp_head);
//	ft_rotate(data->head);

	
	while (!(ft_check_swap(data->head, data)))
	{
	//	printf("\n\tFINE\n");
		//tmp_head = data->start;
		while ((*data->head)->next && (*data->head)->num < (*data->head)->next->num)
		{
			ft_rotate(data->head);//data->head = data->head->next;
			ops++;
		}
		if ((*data->head)->num > (*data->head)->next->num)
		{
			ft_swap(data->head);
			ops++;
		}
		printf("data-minest: %d\n", data->lowest->num);
		while ((*data->head)->num != /*data->start->num) */ data->lowest->num)
		{
			printf("headnum: %d\n", (*data->head)->num );
			printf("\n\tFINE\n");
			ft_rotate(data->head);
			ops++;
		}
		ft_print_stack(data->head);
	}
	
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

void	ft_push_swap(t_data *data)
{
		printf("data-minest: %d\t data-maxest: %d \nstart->num: %d\ttail-num: %d\n", (data->lowest)->num, (data->maxest)->num, data->start->num, data->tail->num);
	int	a;

	a = ft_single(data);
	printf("mosse: %d\n", a);
//	ft_print_stack(data->head);
}