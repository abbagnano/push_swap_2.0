/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halfing_from_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:34:32 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/18 14:34:34 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_halfing_stack(t_list **head, t_list **dst_head,
							int min_pos, t_data *data)
{
	int	x;
	int	med;
	int	len;

	x = 0;
	len = ft_listlen(head, &min_pos);
	med = min_pos + len / 2;
	while (x < len / 2)
	{
		if ((*head)->pos < med)
		{
			if ((*head)->next->pos < med && (*head)->next->pos < (*head)->pos
				&& (*head)->next->pos > 0)
				ft_sa(head, data);
			ft_pb(head, dst_head, data);
			x++;
			ft_sort_pushed(dst_head, data, med);
		}
		else
		{
			if ((*head)->next->pos >= med && (*head)->next->pos < (*head)->pos)
				ft_sa(head, data);
			ft_ra(head, data);
		}
	}
}

void	ft_way_back(t_list **head, int *back, t_data *data)
{
	while (*back)
	{
		if (ft_rev_rot(head))
		{
			ft_write("rra\n");
			data->ops++;
			(*back)--;
		}
	}
}

void	ft_halfing_stack_2(t_list **head, t_list **dst_head,
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
	while (x < len / 2)
	{
		if ((*head)->pos < med && ++x)
			ft_under_med(head, dst_head, med, data);
		else
			ft_over_med(head, &back, med, data);
	}
	ft_way_back(head, &back, data);
}

void	ft_start_halfing(t_list **head, t_list **dst_head, t_data *data)
{
	int	len;
	int	min_pos;

	len = ft_listlen(head, &min_pos);
	while (len > 2 && ft_check_pushed(data->head, data))
	{
		if (*dst_head)
			(*dst_head)->pos *= -1;
		ft_halfing_stack(head, dst_head, min_pos, data);
		len = ft_listlen(head, &min_pos);
	}
	if ((*data->head)->num != min_pos)
	{
		ft_put_lower_at_head(data->head, data, min_pos);
	}
}

void	ft_start_halfing_2(t_list **head, t_list **dst_head, t_data *data)
{
	int	len;
	int	min_pos;

	len = ft_listlen(head, &min_pos);
	while (len > 2 && ft_check_pushed(data->head, data))
	{
		if (*dst_head)
			(*dst_head)->pos *= -1;
		ft_halfing_stack_2(head, dst_head, min_pos, data);
		len = ft_listlen(head, &min_pos);
	}
}
