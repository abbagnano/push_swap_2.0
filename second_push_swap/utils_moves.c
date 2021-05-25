/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:35:22 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/18 14:35:24 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_ra(t_list **dst_head, t_data *data)
{
	if (ft_rotate(dst_head))
	{
		if (!data->write_flag)
			ft_write("ra\n");
		data->ops++;
	}
}

void	ft_rb(t_list **dst_head, t_data *data)
{
	if (ft_rotate(dst_head))
	{
		if (!data->write_flag)
			ft_write("rb\n");
		data->ops++;
	}
}

void	ft_sa(t_list **dst_head, t_data *data)
{
	if (ft_swap(dst_head))
	{
		if (!data->write_flag)
			ft_write("sa\n");
		data->ops++;
	}
}

void	ft_sb(t_list **dst_head, t_data *data)
{
	if (ft_swap(dst_head))
	{
		if (!data->write_flag)
			ft_write("sb\n");
		data->ops++;
	}
}

void	ft_pb(t_list **head, t_list **dst_head, t_data *data)
{
	ft_push(head, dst_head);
	if (!data->write_flag)
		ft_write("pb\n");
	data->ops++;
}
