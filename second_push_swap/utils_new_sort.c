/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_new_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:35:10 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/25 18:01:16 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_init_pos(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		tmp->pos = 1;
		tmp->idx = 1;
		tmp = tmp->next;
	}
}

void	ft_check_pos(t_data *data, int num)
{
	t_list	*tmp;

	tmp = *data->head;
	while (tmp)
	{
		if (tmp->num > num)
		{
			tmp->pos++;
		}
		tmp = tmp->next;
	}
}

void	ft_get_range(t_data *data)
{
	t_list	*tmp;

	tmp = *data->head;
	data->len = 0;
	data->min = tmp->num;
	data->max = tmp->num;
	data->max_idx = tmp;
	ft_init_pos(data->head);
	while (tmp)
	{
		if (tmp->num > data->max)
			data->max = tmp->num;
		else if (tmp->num < data->min)
			data->min = tmp->num;
		ft_check_pos(data, tmp->num);
		ft_subseq(tmp);
		if (tmp->idx > data->max_idx->idx)
			data->max_idx = tmp;
		tmp = tmp->next;
		data->len++;
	}
}

int	ft_find_lower(t_list **head, int min)
{
	t_list	*tmp;
	int		x;

	tmp = *head;
	x = 0;
	while (tmp && tmp->pos != min)
	{
		tmp = tmp->next;
		x++;
	}
	return (x);
}

void	ft_put_lower_at_head(t_list **head, t_data *data, int min)
{
	if (ft_find_lower(head, min) <= data->len / 2)
	{
		while ((*head)->pos != min)
		{
			if ((*data->b_head) && (*data->b_head)->pos == (*head)->pos - 1)
				ft_pa(data->b_head, data->head, data);
			else if ((*data->b_head)
				&& (*data->b_head)->pos == (*head)->pos + 1)
			{
				ft_ra(data->head, data);
				ft_pa(data->b_head, data->head, data);
			}
			ft_ra(data->head, data);
			ft_check_pa(data);
		}
	}
	else
	{
		while ((*head)->pos != min)
		{
			ft_check_pa(data);
			ft_rra(data->head, data);
			ft_check_pa(data);
		}
	}
}
