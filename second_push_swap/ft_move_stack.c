/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:34:09 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/25 18:00:09 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_swap(t_list **head)
{
	t_list	*old_first;
	t_list	*old_second;

	if (!(head) || !(*head) || !((*head)->next))
		return (0);
	old_first = *head;
	old_second = (*head)->next;
	old_first->next = old_second->next;
	old_second->next = old_first;
	*head = old_second;
	return (1);
}

void	ft_push(t_list **topush, t_list **head)
{
	t_list	*nodetopush;

	nodetopush = *topush;
	*topush = (*topush)->next;
	nodetopush->next = *head;
	*head = nodetopush;
}

int	ft_rotate(t_list **head)
{
	t_list	*last;
	t_list	*tmp;

	if (!(head) || !(*head) || !(*head)->next)
		return (0);
	last = *head;
	tmp = (*head)->next;
	while (last->next)
		last = last->next;
	last->next = *head;
	last->next->next = NULL;
	*head = tmp;
	return (1);
}

int	ft_rev_rot(t_list **head)
{
	t_list	*last;
	t_list	*tmp;

	if (!(head) || !(*head) || !((*head)->next))
		return (0);
	last = *head;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = *head;
	*head = tmp;
	return (1);
}
