/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:59:46 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/25 17:59:48 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_ops_rra(t_data *data, t_list *tmp_b)
{
	int		rra;
	int		min;
	t_list	*tmp_a;

	rra = ft_listlen(data->head, &min) - 1;
	tmp_a = *data->head;
	while (tmp_a && tmp_a->next)
	{
		if (tmp_b->num > tmp_a->num && tmp_b->num < tmp_a->next->num)
			return (rra);
		else if (tmp_a->num > tmp_a->next->num)
		{
			if (tmp_b->num > tmp_a->num || tmp_b->num < tmp_a->next->num)
				return (rra);
		}
		rra--;
		tmp_a = tmp_a->next;
	}
	return (0);
}

int	ft_ops_ra(t_data *data, t_list *tmp_b)
{
	int		ra;
	t_list	*tmp_a;

	ra = 1;
	tmp_a = *data->head;
	while (tmp_a->next)
	{
		if (tmp_b->num > tmp_a->num && tmp_b->num < tmp_a->next->num)
			return (ra);
		else if (tmp_a->num > tmp_a->next->num)
		{
			if (tmp_b->num > tmp_a->num || tmp_b->num < tmp_a->next->num)
				return (ra);
		}
		ra++;
		tmp_a = tmp_a->next;
	}
	return (0);
}

void	ft_mosse(t_data *data)
{
	int		rb;
	int		rrb;
	int		min;
	t_list	*tmp;

	rb = 0;
	rrb = ft_listlen(data->b_head, &min);
	tmp = *data->b_head;
	while (tmp)
	{
		tmp->ops.rb = rb;
		tmp->ops.rrb = rrb;
		tmp->ops.ra = ft_ops_ra(data, tmp);
		tmp->ops.rra = ft_ops_rra(data, tmp);
		tmp = tmp->next;
		rb++;
		rrb--;
	}
}

void	ft_empty_b(t_data *data)
{
	while (*data->b_head)
	{
		ft_mosse(data);
		ft_calc(data);
		ft_best_pa(data);
	}
}
