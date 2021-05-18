/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halfing_from_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:34:41 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/18 14:34:43 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_find_next(t_data *data, int *x)
{
	if (!ft_check_pushed(data->head, data))
		*x = ft_find_next_pa(data->b_head, (*data->head)->pos - 1);
	else
		*x = ft_find_next_pa(data->b_head, (*data->head)->next->pos - 1);
	if ((*data->b_head)->pos < 0
		&& -(*data->b_head)->pos == (*data->head)->pos - 1)
		(*data->b_head)->pos *= -1;
}

void	ft_push_back(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (*data->b_head)
	{
		ft_find_next(data, &x);
		y = ft_save_line(data, &x);
		if (y == 1)
			ft_pa(data->b_head, data->head, data);
		else if (y == 2)
			ft_sb(data->b_head, data);
		else if (y == 3)
			ft_pa(data->b_head, data->head, data);
		else if (y == 4)
		{
			ft_pa(data->b_head, data->head, data);
			ft_sa(data->head, data);
		}
		else if (y == 5)
			ft_sa(data->head, data);
		else
			ft_backing(data);
	}
}

void	ft_way_back_b(t_list **head, int *back, t_data *data)
{
	while (*back)
	{
		if (ft_rev_rot(head))
		{
			ft_write("rrb\n");
			data->ops++;
			(*back)--;
		}
	}
}

void	ft_halfing_stack_rev(t_list **head, t_list **dst_head,
							int min_pos, t_data *data)
{
	int	x;
	int	med;
	int	len;
	int	back;

	x = 0;
	back = 0;
	len = ft_listlen(head, &min_pos);
	med = min_pos + len / 2;
	if (!(len % 2))
		x++;
	while (x < len / 2)
	{
		if ((*head) && (*head)->pos > med && ++x)
			ft_over_med_b(head, dst_head, med, data);
		else
			ft_under_med_b(head, &back, med, data);
	}
	ft_way_back_b(head, &back, data);
}

void	ft_halfing_back(t_list **head, t_list **dst_head, t_data *data)
{
	int	len;
	int	min_pos;

	len = ft_listlen(head, &min_pos);
	if (*dst_head)
		(*dst_head)->pos *= -1;
	ft_halfing_stack_rev(head, dst_head, min_pos, data);
	len = ft_listlen(head, &min_pos);
	return ;
}
