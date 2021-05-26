/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:59:57 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/25 17:59:59 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_check_sort(t_data *data)
{
	t_list	*tmp;

	tmp = *data->head;
	if (*data->b_head)
		ft_exit("KO!\n", data);
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			ft_exit("KO!\n", data);
		tmp = tmp->next;
	}
	ft_exit("OK!\n", data);
}

void	ft_check_op(char *line, int len, t_data *data)
{
	if (len == 3 && !ft_strncmp(line, "rrr", len))
		ft_rrr(data);
	else if (len == 3 && !ft_strncmp(line, "rra", len))
		ft_rra(data->head, data);
	else if (len == 3 && !ft_strncmp(line, "rrb", len))
		ft_rrb(data->b_head, data);
	else if (len == 2 && !ft_strncmp(line, "rr", len))
		ft_rr(data);
	else if (len == 2 && !ft_strncmp(line, "ra", len))
		ft_ra(data->head, data);
	else if (len == 2 && !ft_strncmp(line, "rb", len))
		ft_rb(data->b_head, data);
	else if (len == 2 && !ft_strncmp(line, "ss", len))
		ft_ss(data);
	else if (len == 2 && !ft_strncmp(line, "sa", len))
		ft_sa(data->head, data);
	else if (len == 2 && !ft_strncmp(line, "sb", len))
		ft_sb(data->b_head, data);
	else if (len == 2 && !ft_strncmp(line, "pa", len))
		ft_pa(data->b_head, data->head, data);
	else if (len == 2 && !ft_strncmp(line, "pb", len))
		ft_pb(data->head, data->b_head, data);
	else
		ft_exit("problem op\n", data);
}

void	ft_make_ops(t_data *data)
{
	t_read	*tmp;
	int		len;

	tmp = NULL;
	len = 0;
	if (data->to_do && *data->to_do)
		tmp = *data->to_do;
	while (tmp)
	{
		len = ft_strlen(tmp->line);
		ft_check_op(tmp->line, len, data);
		tmp = tmp->next;
	}
}
