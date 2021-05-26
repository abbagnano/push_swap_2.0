/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subseq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:00:25 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/25 18:00:30 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_subseq(t_list *tmp)
{
	int		idx;
	int		num;

	num = tmp->num;
	idx = tmp->idx;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->num > num && tmp->idx <= idx)
			tmp->idx++;
		tmp = tmp->next;
	}
}

int	ft_next_idx(t_list *tmp, int max_idx, int max_data)
{
	tmp = tmp->next;
	while (tmp && tmp->num != max_data)
	{
		if (tmp->idx == max_idx)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_sign_idx(t_data *data, int max_idx, int max_data)
{	
	t_list	*tmp;

	tmp = *data->head;
	while (tmp && tmp->num != max_data)
	{
		if (tmp->idx == max_idx && !ft_next_idx(tmp, max_idx, max_data))
		{
			tmp->idx *= -1;
			return (tmp->num);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_check_index(t_data *data)
{
	int		max_idx;
	int		max_data;

	max_idx = data->max_idx->idx;
	max_data = data->max_idx->num;
	while (max_idx > 0)
	{
		max_idx--;
		max_data = ft_sign_idx(data, max_idx, max_data);
	}
}

void	ft_split_seq(t_data *data, int max_data)
{
	int		idx;

	idx = data->max_idx->idx;
	idx--;
	while (idx)
	{
		if ((*data->head)->idx >= 0)
		{
			if (idx == data->max_idx->idx - 1 && (*data->head)->num > max_data)
			{
				max_data = (*data->head)->num;
				(*data->head)->idx = -1;
				ft_ra(data->head, data);
			}
			else
				ft_pb(data->head, data->b_head, data);
		}
		else
		{
			idx--;
			ft_ra(data->head, data);
		}
	}
	ft_keep_pb(data, data->max_idx->idx);
}
