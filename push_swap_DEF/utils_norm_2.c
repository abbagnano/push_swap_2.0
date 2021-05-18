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

void	ft_pa(t_list **head, t_list **dst_head, t_data *data)
{
	ft_push(head, dst_head);
	ft_write("pa\n");
	data->ops++;
}

void	ft_backing(t_data *data)
{
	ft_halfing_back(data->b_head, data->head, data);
	if (ft_check_pushed(data->head, data))
		ft_start_halfing_2(data->head, data->b_head, data);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void	ft_get_sign(char c, int *neg)
{
	if (c == '-')
		(*neg)++;
}
