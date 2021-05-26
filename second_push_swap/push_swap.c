/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:34:49 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/25 18:00:53 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_check_num(long int tot, t_list **head, t_data *data)
{
	t_list	*tmp;

	tmp = *head;
	if (tot > 2147483647 || tot < -2147483648)
		ft_exit("Error: out of INT range\n", data);
	while (tmp)
	{
		if (tot == tmp->num)
			ft_exit("Error: duplicated nums\n", data);
		tmp = tmp->next;
	}
}

void	ft_add_num(long int tot, t_list **head, t_data *data)
{
	t_list	*new;
	t_list	*tmp;

	ft_check_num(tot, head, data);
	tmp = *head;
	new = (t_list *)malloc(sizeof(t_list) * 1);
	new->num = tot;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_split_str(char *str, t_data *data)
{
	long int	tot;
	int			neg;

	while (*str)
	{
		neg = 0;
		tot = 0;
		while (ft_isspace(*str))
			str++;
		if (*str == '\0')
			return ;
		if (*str == '+' || *str == '-')
			ft_get_sign(*str++, &neg);
		if ((*str < '0' || *str > '9') && *str != '\0')
			ft_exit("Error\n", data);
		while (*str >= '0' && *str <= '9')
			tot = tot * 10 + *str++ - 48;
		if (*str != '\0' && !ft_isspace(*str))
			ft_exit("Error\n", data);
		if (neg)
			tot *= -1;
		ft_add_num(tot, data->head, data);
	}
	return ;
}

void	ft_to_stack(char **av, int ac, t_data *data)
{
	int	x;

	x = 1;
	while (x < ac)
		ft_split_str(av[x++], data);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.head = (t_list **)malloc(sizeof(t_list *) * 1);
	data.b_head = (t_list **)malloc(sizeof(t_list *) * 1);
	*data.head = NULL;
	*data.b_head = NULL;
	data.write_flag = 0;
	if (ac == 1)
		ft_exit("Error: invalid args!\n", &data);
	ft_to_stack(av, ac, &data);
	if (!*data.head)
		ft_exit("Error: wrong args!\n", &data);
	ft_get_range(&data);
	ft_check_index(&data);
	if (ft_keep_swapping(data.head, &data) && data.len > 5)
	{
		ft_split_seq(&data, data.max_idx->num);
		ft_empty_b(&data);
	}
	else if (ft_keep_swapping(data.head, &data) && data.len <= 5)
		ft_up_to_five(&data);
	ft_put_lower_at_head(data.head, &data, 1);
	ft_exit("", &data);
}
