/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:34:20 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/18 14:34:22 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_sort_pushed(t_list **dst_head, t_data *data, int med)
{
	data->b_tail = ft_get_tail(dst_head, data->b_tail);
	if ((*dst_head)->next && (*dst_head)->next->pos > (*dst_head)->pos)
	{
		if ((*dst_head)->pos == med)
			ft_rb(dst_head, data);
		else if ((*dst_head)->pos > data->b_tail->pos)
			ft_sb(dst_head, data);
		else
			ft_rb(dst_head, data);
	}
}

int	ft_find_next_pa(t_list **head, int next)
{
	t_list	*tmp;
	int		x;

	x = 0;
	tmp = *head;
	while (++x && tmp)
	{
		if (tmp->pos < 0 && -tmp->pos == next)
			return (x);
		else if (tmp->pos == next)
			return (x);
		tmp = tmp->next;
	}
	return (x);
}

int	ft_check_pushed(t_list **head, t_data *data)
{
	t_list	*tmp;

	tmp = *head;
	(void)data;
	while (tmp->next)
	{
		if (tmp->next && tmp->pos != tmp->next->pos - 1 )
		{
			if (tmp->next->pos < 0 && tmp->pos == -tmp->next->pos - 1)
				break ;
			else if (tmp->pos < 0 && tmp->pos == -tmp->next->pos - 1)
				break ;
			return (1);
		}
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	return (0);
}

void	ft_sort_by_pos(t_data *data)
{
	if (!ft_keep_swapping(data->head, data))
	{
		if ((*data->head)->num != data->min)
			ft_put_lower_at_head(data->head, data, 1);
		return ;
	}
	ft_start_halfing(data->head, data->b_head, data);
	ft_push_back(data);
	return ;
}
