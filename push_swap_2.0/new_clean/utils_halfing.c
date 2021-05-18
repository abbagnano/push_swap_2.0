#include "libswap.h"

void	ft_under_med(t_list **head, t_list **dst_head, int med, t_data *data)
{
	if ((*head)->next->pos < med && (*head)->next->pos < (*head)->pos
		&& (*head)->next->pos > 0)
		ft_sa(head, data);
	ft_pb(head, dst_head, data);
	ft_sort_pushed(dst_head, data, med);
}

void	ft_over_med(t_list **head, int *back, int med, t_data *data)
{
	if ((*head)->next->pos >= med && (*head)->next->pos < (*head)->pos)
		ft_sa(head, data);
	if (ft_rotate(head))
	{
		ft_write("ra\n");
		data->ops++;
		(*back)++;
	}
}

void	ft_over_med_b(t_list **head, t_list **dst_head, int med, t_data *data)
{
	if ((*head)->next && (*head)->next->pos > med
		&& (*head)->next->pos > (*head)->pos)
		ft_sb(head, data);
	ft_pa(head, dst_head, data);
	if ((*dst_head)->next && (*dst_head)->next->pos > 0
		&& (*dst_head)->next->pos < (*dst_head)->pos)
		ft_sa(dst_head, data);
}

void	ft_under_med_b(t_list **head, int *back, int med, t_data *data)
{
	if ((*head)->next && (*head)->next->pos <= med
		&& ((*head)->next->pos == (*head)->pos + 1 ))
		ft_sb(head, data);
	if (ft_rotate(head))
	{
		ft_write("rb\n");
		data->ops++;
		(*back)++;
	}
}

int	ft_save_line(t_data *data, int *x)
{
	if (!ft_check_pushed(data->head, data)
		&& (*data->b_head)->pos == (*data->head)->pos - 1)
		return (1);
	else if ((*data->b_head)->next
		&& (*data->b_head)->next->pos > (*data->b_head)->pos && *x < 3)
		return (2);
	else if (!ft_check_pushed(data->head, data)
		&& (*data->b_head)->pos == (*data->head)->pos - 2 && *x < 4)
		return (3);
	else if ((*data->b_head)->pos == (*data->head)->pos + 1)
		return (4);
	else if ((*data->head)->pos == (*data->head)->next->pos + 1
		|| (*data->head)->pos == -(*data->head)->next->pos + 1 )
	{
		if ((*data->head)->next->pos < 0)
			(*data->head)->next->pos *= -1;
		return (5);
	}
	return (0);
}
