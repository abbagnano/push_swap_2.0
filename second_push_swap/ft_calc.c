#include "libswap.h"

void	ft_sort_five(t_data *data)
{
	int	min;
	int	max;

	min = data->min;
	max = data->max;
	data->min = 1;
	data->max = data->len;
	if ((*data->head)->pos == data->min)
		data->min++;
	else if ((*data->head)->pos == data->max)
		data->max--;
	ft_pb(data->head, data->b_head, data);
	if ((*data->head)->pos == data->min)
		data->min++;
	else if ((*data->head)->pos == data->max
		&& (*data->b_head)->pos != data->max - 1)
		data->max--;
	else if ((*data->head)->pos == data->max
		&& (*data->b_head)->pos == data->max - 1)
		data->max -= 2;
	ft_pb(data->head, data->b_head, data);
	ft_sort_five2(data, min, max);
}

void	ft_sort_five2(t_data *data, int min, int max)
{
	if (ft_keep_swapping_pos(data->head, data)
		&& (*data->b_head)->next->pos == (*data->head)->next->pos + 1)
		ft_ss(data);
	else if (ft_keep_swapping_pos(data->head, data))
		ft_sa(data->head, data);
	data->max = max;
	data->min = min;
	ft_empty_b(data);
	ft_listlen(data->head, &min);
	ft_put_lower_at_head(data->head, data, min);
}

void	ft_up_to_five(t_data *data)
{
	if (data->len <= 3)
		ft_sa(data->head, data);
	else if (data->max_idx->idx < 3)
		ft_sort_five(data);
	else
	{
		ft_split_seq(data, data->max_idx->num);
		ft_empty_b(data);
	}
}

int	ft_flagging_tot(int *tot_r, int tot_rr,
			int tot_ra_rrb, int tot_rb_rra)
{
	if (*tot_r < tot_rr && *tot_r < tot_ra_rrb && *tot_r < tot_rb_rra)
		return (1);
	else if (tot_rr < *tot_r && tot_rr < tot_ra_rrb && tot_rr < tot_rb_rra)
	{
		*tot_r = tot_rr;
		return (2);
	}
	else if (tot_ra_rrb < *tot_r && tot_ra_rrb < tot_rr
		&& tot_ra_rrb < tot_rb_rra)
	{
		*tot_r = tot_ra_rrb;
		return (3);
	}
	else
	{
		*tot_r = tot_rb_rra;
		return (4);
	}
}

void	ft_calc(t_data *data)
{
	t_list	*tmp;
	int		tot_rr;
	int		tot_ra_rrb;
	int		tot_rb_rra;

	tmp = *data->b_head;
	while (tmp)
	{
		if (tmp->ops.ra > tmp->ops.rb)
			tmp->tot = tmp->ops.ra;
		else
			tmp->tot = tmp->ops.rb;
		if (tmp->ops.rra > tmp->ops.rrb)
			tot_rr = tmp->ops.rra;
		else
			tot_rr = tmp->ops.rrb;
		tot_ra_rrb = tmp->ops.ra + tmp->ops.rrb;
		tot_rb_rra = tmp->ops.rb + tmp->ops.rra;
		tmp->flag = ft_flagging_tot(&tmp->tot, tot_rr, tot_ra_rrb, tot_rb_rra);
		tmp = tmp->next;
	}
}
