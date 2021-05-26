/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_pa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:59:30 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/25 17:59:32 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_put_ra_rrb(t_data *data, t_list *temp_b)
{
	int		x;

	x = temp_b->ops.ra;
	while (x > 0)
	{
		ft_ra(data->head, data);
		x--;
	}
	x = temp_b->ops.rrb;
	while (x > 0)
	{
		ft_rrb(data->b_head, data);
		x--;
	}
	ft_pa(data->b_head, data->head, data);
}

void	ft_put_rb_rra(t_data *data, t_list *temp_b)
{
	int		x;

	x = temp_b->ops.rb;
	while (x > 0)
	{
		ft_rb(data->b_head, data);
		x--;
	}
	x = temp_b->ops.rra;
	while (x > 0)
	{
		ft_rra(data->head, data);
		x--;
	}
	ft_pa(data->b_head, data->head, data);
}

void	ft_put_reverse(t_data *data, t_list *temp_b)
{	
	int		x;

	if (temp_b->ops.rra > temp_b->ops.rrb)
		x = temp_b->ops.rrb;
	else
		x = temp_b->ops.rra;
	while (x > 0)
	{
		x--;
		ft_rrr(data);
	}
	if (temp_b->ops.rra > temp_b->ops.rrb)
		x = temp_b->ops.rra - temp_b->ops.rrb;
	else
		x = temp_b->ops.rrb - temp_b->ops.rra;
	while (x > 0)
	{
		x--;
		if (temp_b->ops.rra > temp_b->ops.rrb)
			ft_rra(data->head, data);
		else
			ft_rrb(data->b_head, data);
	}
	ft_pa(data->b_head, data->head, data);
}

void	ft_put_rotate(t_data *data, t_list *temp_b)
{	
	int		x;

	if (temp_b->ops.ra > temp_b->ops.rb)
		x = temp_b->ops.rb;
	else
		x = temp_b->ops.ra;
	while (x > 0)
	{		
		x--;
		ft_rr(data);
	}
	if (temp_b->ops.ra > temp_b->ops.rb)
		x = temp_b->ops.ra - temp_b->ops.rb;
	else
		x = temp_b->ops.rb - temp_b->ops.ra;
	while (x > 0)
	{
		x--;
		if (temp_b->ops.ra > temp_b->ops.rb)
			ft_ra(data->head, data);
		else
			ft_rb(data->b_head, data);
	}
	ft_pa(data->b_head, data->head, data);
}

void	ft_best_pa(t_data *data)
{
	t_list	*tmp;
	t_list	*best;

	tmp = *data->b_head;
	best = tmp;
	while (tmp)
	{
		if (tmp->tot < best->tot)
			best = tmp;
		tmp = tmp->next;
	}
	if (best->flag == 1)
		ft_put_rotate(data, best);
	else if (best->flag == 2)
		ft_put_reverse(data, best);
	else if (best->flag == 3)
		ft_put_ra_rrb(data, best);
	else
		ft_put_rb_rra(data, best);
}
