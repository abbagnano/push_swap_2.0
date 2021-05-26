/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:00:16 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/25 18:00:17 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_check_buf(char *buf, int len)
{
	if (len == 3 && !ft_strncmp(buf, "rrr", len))
		return (1);
	else if (len == 3 && !ft_strncmp(buf, "rra", len))
		return (1);
	else if (len == 3 && !ft_strncmp(buf, "rrb", len))
		return (1);
	else if (len == 2 && !ft_strncmp(buf, "rr", len))
		return (1);
	else if (len == 2 && !ft_strncmp(buf, "ra", len))
		return (1);
	else if (len == 2 && !ft_strncmp(buf, "rb", len))
		return (1);
	else if (len == 2 && !ft_strncmp(buf, "ss", len))
		return (1);
	else if (len == 2 && !ft_strncmp(buf, "sa", len))
		return (1);
	else if (len == 2 && !ft_strncmp(buf, "sb", len))
		return (1);
	else if (len == 2 && !ft_strncmp(buf, "pa", len))
		return (1);
	else if (len == 2 && !ft_strncmp(buf, "pb", len))
		return (1);
	return (0);
}

int	ft_buf_to_node(int len, int x, char *buf, t_read *new)
{
	int	y;

	y = 0;
	if (!ft_check_buf(buf + x, len))
		return (-1);
	new->line = (char *)malloc(sizeof(char) * (len + 1));
	new->line[len] = '\0';
	while (buf[x] != '\n' && buf[x] != '\0')
	{
		new->line[y++] = buf[x];
		x++;
	}
	new->line[y] = '\0';
	new->next = NULL;
	x++;
	return (x);
}

void	ft_append_read(t_read *new, t_read **head)
{
	t_read	*tmp;

	tmp = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_buf_to_list(char *buf, t_data *data)
{
	int		len;
	int		x;
	t_read	*new;

	x = 0;
	while (buf && buf[x])
	{
		len = ft_strchr('\n', buf + x);
		if (len < 0)
			break ;
		else if (len > 3 || len < 2)
		{
			free(buf);
			ft_exit("Error: wrong op!\n", data);
		}
		new = (t_read *)malloc(sizeof(t_read) * 1);
		x = ft_buf_to_node(len, x, buf, new);
		if (x < 0)
		{
			free(buf);
			ft_exit("Error: wrong op2!\n", data);
		}
		ft_append_read(new, data->to_do);
		new = new->next;
	}
}

void	ft_read_ops(t_data *data)
{
	char	*buf;
	int		r;

	buf = (char *)malloc(sizeof(char) * 10240);
	buf[10239] = '\0';
	r = 1;
	while (r > 0)
	{
		r = read(0, buf, 10239);
		buf[r] = '\0';
		if (buf[0] == '\0')
			return ;
		ft_buf_to_list(buf, data);
	}
	free(buf);
}
