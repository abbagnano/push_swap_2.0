#include "libswap.h"

int		ft_strlen(char *str)
{
	int x;

	x = 0;
	while (str && str[x])
		x++;
//	printf("%d\n", x);
	return (x);
}

void	ft_write(char *str)
{
	write(1, str, ft_strlen(str));
	return ;
}

void	ft_exit(char *str, t_data *data)
{
	t_list *tmp;

	
	ft_write(str);
	while (*data->head)
	{
		tmp = *data->head;
		*data->head = (*data->head)->next;
		free(tmp);	
	}
	free(data->head);
	while (*data->b_head)
	{
		tmp = *data->b_head;
		*data->b_head = (*data->b_head)->next;
		free(tmp);	
	}
	free(data->b_head);
	exit (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int x;

	x = 0;
	while (s1 && s2 && s1[x] && s2[x] && s1[x] == s2[x])
	{
		x++;
		if (!s1[x]) // && !(s2[x] >= '0' && s2[x] <= '9'))
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
	
	new = (t_list *)malloc(sizeof(t_list) * 1);
	new->num = tot;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else 
	{
		tmp = *head;
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
		if ((*str < '0' || *str > '9') && *str != '\0' && printf("%s\n", str))
			ft_exit("Error\n", data);
		while (*str >= '0' && *str <= '9')
			tot = tot * 10 + *str++ - 48;
		if (*str != '\0' && !(*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r' || *str == ' '))
			ft_exit("Error: problem with argv string!\n", data);
		if (neg)
			tot *= -1;
		ft_add_num(tot, data->head, data);
	}
	return ;
}

void    ft_print_stack(t_list **head)
{
	printf("\n\tft_print_stack - start\n");
	t_list *stack;
	
	stack = *head;
	 while (stack != NULL)
	{
		printf("stack[]= %d\n", stack->num);
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

char	*ft_buf_to_txt(char *buf, char *txt)
{
	int		x;
	int		y;
	char	*tmp;

	x = 0;
	y = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(txt) + 1));
//	printf("qwe\n");
	while (txt && txt[x])
	{
		tmp[x] = txt[x];
		x++;
	}
	while (buf && buf[y])
	{
		tmp[x + y] = buf[y];
		y++;
	}
	tmp[x + y] = '\0';
	free(txt);
	return (tmp);
}

void	ft_check_buf(char *buf, int r, t_data *data)
{
	(void)r;
//	printf("buf:%s-\tcmp:%d\n", buf, ft_strcmp("rra", buf));

//	if (buf[r - 1] != '\n')
//		ft_exit("Error1: wrong instruction!\n", data);
	if (ft_strcmp("rra", buf) != 0 && ft_strcmp("rrb", buf) != 0 && ft_strcmp("rrr", buf) != 0
		&& ft_strcmp("sa", buf) != 0 && ft_strcmp("sb", buf) != 0 && ft_strcmp("ss", buf) != 0
		&& ft_strcmp("pa", buf) != 0 && ft_strcmp("pb", buf) != 0
		&& ft_strcmp("ra", buf) != 0 && ft_strcmp("rb", buf) != 0 && ft_strcmp("rr", buf) != 0)
		ft_exit("Error: wrong instruction!\n", data);

}

void	ft_read_instr(t_data *data)
{
	char	*buf;
	int		r;
	buf = (char *)malloc(sizeof(char) * 5);
	buf[4] = '\0';
	r = 1;
	while (r > 0)
	{
		r = read(0, buf, 4);
		buf[r] = '\0';
		if (buf[0] == '\n' || buf[0] == '\0')
			break ;
		ft_check_buf(buf, r, data);		
		data->txt = ft_buf_to_txt(buf, data->txt);
		buf[0] = '\0';
	}
	
	free(buf);
}

void	ft_move_stack(char *op, t_data *data)
{
//	int	len;

//	len = ft_strlen(op);

	if (ft_strcmp("rra", op) == 0)
		ft_rev_rot(data->head);
	else if (ft_strcmp("rrb", op) == 0)
		ft_rev_rot(data->b_head);
	else if (ft_strcmp("rrr", op) == 0)
	{
		ft_rev_rot(data->head);
		ft_rev_rot(data->b_head);
	}
	else if (ft_strcmp("sa", op) == 0)
		ft_swap(data->head);
	else if (ft_strcmp("sb", op) == 0)
		ft_swap(data->b_head);
	else if (ft_strcmp("ss", op) == 0)
	{
		ft_swap(data->head);
		ft_swap(data->b_head);
	}
	else if (ft_strcmp("pa", op) == 0 && (*data->b_head))
		ft_push(data->b_head, data->head); 
	else if (ft_strcmp("pb", op) == 0 && (*data->head))
		ft_push(data->head, data->b_head); 
	else if (ft_strcmp("ra", op) == 0)
		ft_rotate(data->head);
	else if (ft_strcmp("rb", op) == 0)
		ft_rotate(data->b_head);
	else if (ft_strcmp("rr", op) == 0)
	{
		ft_rotate(data->head);
		ft_rotate(data->b_head);
	}
}

void	ft_make_instr(t_data *data)
{
	char	*op;
	int		x;
	int		y;

//	printf("-\n%s-\n", data->txt);
	y = 0;
	if (!data->txt)
		return ;
	op = (char *)malloc(sizeof(char) * 5);
	op[4] = '\0';
	while (data->txt[y])
	{
		x = -1;
		while (op[++x])
			op[x] = '\0';
		x = 0;
		while (data->txt[y] && data->txt[y] != '\n')
		{
			op[x] = data->txt[y];
			x++;
			y++;
		}
		op[x] = '\0';
		y++;
		if (x)
			ft_move_stack(op, data);
	}
	free(op);
}

void	ft_check_sort(t_data *data)
{
	int		min;
	t_list	*tmp;

	if (*data->b_head)
		ft_exit("KO!\n", data) ;
	tmp = *data->head;
	min = tmp->num;
	while (tmp != NULL)
	{
		if (tmp->num < min)
			ft_exit("KO!\n", data) ;
		min = tmp->num;
		tmp = tmp->next;
	}
	ft_exit("OK!\n", data) ;
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
	data.txt = NULL;

	ft_to_stack(av, ac, &data);

	ft_read_instr(&data);
		
	ft_make_instr(&data);

	ft_check_sort(&data);	
	
	ft_exit("", &data);
	
}