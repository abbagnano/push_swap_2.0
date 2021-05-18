#include "libswap.h"

t_list	*ft_get_tail(t_list **head, t_list *tail)
{
	tail = *head;
	while (tail->next)
		tail = tail->next;
	return (tail);
}

int	ft_keep_swapping(t_list **head, t_data *data)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp->next)
	{
		if (tmp->num == data->max && tmp->next->num == data->min)
			tmp = tmp->next;
		if (tmp->next && tmp->num > tmp->next->num)
			return (1);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	if (tmp->num != data->max && tmp->num > (*head)->num)
		return (1);
	return (0);
}

int	ft_listlen(t_list **head, int *min_pos)
{
	int		x;
	t_list	*tmp;

	tmp = *head;
	x = 0;
	if (tmp->pos < 0)
		tmp->pos *= -1;
	*min_pos = tmp->pos;
	while (tmp && tmp->pos > 0)
	{
		if (tmp->pos < *min_pos)
			*min_pos = tmp->pos;
		tmp = tmp->next;
		x++;
	}
	return (x);
}
