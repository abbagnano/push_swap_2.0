#include "libswap.h"

void	ft_get_range(t_data *data)
{
//	int min;
//	int max;
	t_list *tmp;

	data->lowest = (t_list *)malloc(sizeof(t_list ) * 1);
	data->maxest = (t_list *)malloc(sizeof(t_list ) * 1);
	data->start = (t_list *)malloc(sizeof(t_list *) * 1);
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
		tmp = tmp->next;
	}
	//tmp = *data->head;
	//while (tmp && tmp->num != data->min)
	//	tmp = tmp->next;
	//*data->lowest = tmp;
//	printf("min: %d\t max: %d \n", data->min, data->max);
	printf("data-minest: %d\t data-maxest: %d \nstart->num: %d\n", (data->lowest)->num, (data->maxest)->num, data->start->num);
}

void	ft_push_swap(t_data *data)
{
	t_list *tmp;
	t_flags flags;

	tmp = *data->head;
	flags.sa = 0;
	flags.ra = 0;
	flags.pa = 0;
	while (!(ft_check_swap(data)))
	{
		printf("\nxxxx\n");
		//	faccio check del primo num con il next	->	sa
		if (tmp->num > )
		//	si fa il check del primo con l'ultimo	->	ra
		//	si fa il check con il primo sull-altro stack ->	pa
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