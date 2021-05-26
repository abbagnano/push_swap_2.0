/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:35:46 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/25 18:01:36 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str && str[x])
		x++;
	return (x);
}

void	ft_write(char *str)
{
	write(1, str, ft_strlen(str));
	return ;
}

void	ft_free_read(t_read **head)
{
	t_read	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->line);
		free(tmp);
	}
}

void	ft_free_stack(t_list **head)
{
	t_list	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

void	ft_exit(char *str, t_data *data)
{
	ft_write(str);
	ft_free_stack(data->head);
	free(data->head);
	ft_free_stack(data->b_head);
	free(data->b_head);
	if (data->to_do)
	{
		ft_free_read(data->to_do);
		free(data->to_do);
	}
	exit(0);
}
