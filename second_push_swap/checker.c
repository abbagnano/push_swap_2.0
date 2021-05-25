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

	if (ac == 1)
	{
		ft_write("Error: invalid args!\n");
		return (0);
	}
	data.head = (t_list **)malloc(sizeof(t_list *) * 1);
	data.b_head = (t_list **)malloc(sizeof(t_list *) * 1);
	data.to_do = (t_read **)malloc(sizeof(t_read *) * 1);
	*data.to_do = NULL;
	*data.head = NULL;
	*data.b_head = NULL;
	data.write_flag = 1;
	ft_to_stack(av, ac, &data);
	ft_read_ops(&data);
	ft_make_ops(&data);
	ft_check_sort(&data);
	ft_exit("", &data);
}
