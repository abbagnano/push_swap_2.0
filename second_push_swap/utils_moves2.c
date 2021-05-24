/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_norm_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:35:36 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/18 14:35:38 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_rra(t_list **dst_head, t_data *data)
{
	if (ft_rev_rot(dst_head))
	{
		ft_write("rra\n");
		data->ops++;
	}
}

void	ft_rrb(t_list **dst_head, t_data *data)
{
	if (ft_rev_rot(dst_head))
	{
		ft_write("rrb\n");
		data->ops++;
	}
}

void	ft_pa(t_list **head, t_list **dst_head, t_data *data)
{
	ft_push(head, dst_head);
	ft_write("pa\n");
	data->ops++;
}

void	ft_rr(t_data *data)
{
	ft_rotate(data->head);
	ft_rotate(data->b_head);
	ft_write("rr\n");
	data->ops++;
}

void	ft_rrr(t_data *data)
{
	ft_rev_rot(data->head);
	ft_rev_rot(data->b_head);
	ft_write("rrr\n");
	data->ops++;
}
