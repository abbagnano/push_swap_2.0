#include "libswap.h"

void	ft_check_pa(t_data *data)
{
	if ((*data->b_head) && (*data->b_head)->pos == (*data->head)->pos - 1)
		ft_pa(data->b_head, data->head, data);
}

void	ft_ss(t_data *data)
{
	ft_swap(data->head);
	ft_swap(data->b_head);
	ft_write("ss\n");
	data->ops++;
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
