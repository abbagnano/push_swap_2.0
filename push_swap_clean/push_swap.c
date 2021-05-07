#include "libswap.h"

int		ft_strlen(char *str)
{
	int x;

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

void	ft_free_stack(t_list **head)
{
	t_list *tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);	
	}
}

void	ft_exit(char *str, t_data *data)
{
	//t_list *tmp;

	ft_write(str);
	ft_free_stack(data->head);
	free(data->head);
	ft_free_stack(data->b_head);
	free(data->b_head);
	if (data->backup && *data->backup)
	{
		ft_free_stack(data->backup);
		free(data->backup);
	}
//									printf("exiting.. check leaks!!\n");
//									char buf[2];			//	per i leaks!!
//									read(0, &buf, 1);
	
	exit (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int x;

	x = 0;
	while (s1 && s2 && s1[x] && s2[x] && s1[x] == s2[x])
	{
		x++;
		if (!s1[x] && !(s2[x] >= '0' && s2[x] <= '9'))
			return (0);
	}
	return (s1[x] - s2[x]);
}

void	ft_check_num(long int tot, t_list **head, t_data *data)
{
	t_list *tmp;

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
	ft_check_num(tot, head, data);
	t_list *new;
	t_list *tmp;
	
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
	int	neg;

	while (*str)
	{
		neg = 0;
		tot = 0;
		while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r' || *str == ' ')
			str++;
		if (*str == '-' && *str++)
			neg++;
		else if (*str == '+')
			str++;
		if ((*str < '0' || *str > '9') && *str != '\0')
			ft_exit("Error\n", data);
		while (*str >= '0' && *str <= '9')
			tot = tot * 10 + *str++ - 48;
		if (*str != '\0' && !(*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r' || *str == ' '))
			ft_exit("Error\n", data);
		if (neg)
			tot *= -1;
		ft_add_num(tot, data->head, data);
	}
	return ;
}

void    ft_print_stack(t_list **head)
{
	t_list *stack;
	
	stack = *head;
	 while (stack != NULL)
	{
		printf("=== %d\n", stack->num);

	//	ft_write(ft_itoa(stack->num));
		stack = stack->next;
	}
}

void    ft_to_stack(char **av, int ac, t_data *data)
{
	int x;

	x = 1;
	while (x < ac)
		ft_split_str(av[x++], data);
}

int	ft_check_swap(t_list **head, t_data *data)
{
	int		min;
	t_list	*tmp;

	if (*data->b_head)
		return (0);
	tmp = *head;
	min = tmp->num;
	while (tmp != NULL)
	{
		if (tmp->num < min)
			return (0);
		min = tmp->num;
		tmp = tmp->next;
	}
	return (1);
}


int main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
	{
		ft_write("Error: invalid args!\n");
		return (0);
	}
	data.head = (t_list **)malloc(sizeof(t_list *) * 1);
	data.b_head = (t_list **)malloc(sizeof(t_list *) * 1);
	*data.head = NULL;
	*data.b_head = NULL;
	
	ft_to_stack(av, ac, &data);

	ft_get_range(&data);
//		printf("pre head:\n");
ft_print_stack(data.head);
	if (data.len > 10)
		ft_find_med(data.head, &data);
	else
		ft_push_swap(&data);
	ft_write("\n");
	printf("data->ops: %d\n", data.ops);
//	printf("head:\n");
//	ft_print_stack(data.head);
//								ft_push_swap(&data);
	printf("post head:\n");
ft_print_stack(data.head);
//printf("med.%lld\n", data.med);
//	printf("zxc.%lld\n", data.zxc);
	ft_exit("", &data);
}