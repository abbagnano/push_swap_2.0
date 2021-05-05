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

/*
void    ft_free_stack(t_list **stack, t_data *data)
{	printf("\t\tfreee\n");
	t_list **head;

	head = stack;
	while (*stack)
	{
		stack->next = head;
		stack = NULL;
	}
		
	free(stack);//->next);
	
}
*/

void	ft_exit(char *str, t_data *data)
{
	t_list *tmp;

	
//	tmp = tail;
	ft_write(str);
//	ft_free_stack(&data->stack_a, data);
//  (void)data;
	while (*data->head)
	{
	//	printf("freeeing: %d\n", (*data->head)->num);
		tmp = *data->head;
		*data->head = (*data->head)->next;
		free(tmp);	
	}
	free(data->head);
	while (*data->b_head)
	{
	//	printf("freeeing: %d\n", (*data->head)->num);
		tmp = *data->b_head;
		*data->b_head = (*data->b_head)->next;
		free(tmp);	
	}
	free(data->b_head);
									printf("exiting.. check leaks!!\n");
									char buf[10];			//	per i leaks!!
									read(0, &buf, 9);
	
	exit (0);
//	free(data->stack_a);
//	free(*data->stack_a.next);
//	free(*data->stack_b);
//	free(data->stack_a);
//	free(data->stack_b);
//	free(data);
}
/*
void	ft_add_data(t_data *data, int tot)
{
	printf("\tft_add_data - start\n");
	t_list *stack;

	stack = *data->head;
	//while (data->stack_a != NULL)
	//	data->stack_a = data->stack_a->next;
	printf("tail: %p\n", data->tail);
	if (data->tail != NULL)
		stack = *data->tail;
	stack = (t_list *)malloc(sizeof(t_list) * 1);
	stack->num = tot;
	printf("\nstack[]= %d\n", stack->num);
	stack->next = NULL;
	data->tail = &stack->next;
	//data->head = &stack;
//	printf("\tft_add_data - end\n");
}
*/
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
//	printf("cmp_char: '%c' - '%c'\n", s1[x] , s2[x]);
//	printf("cmp_int: '%d' - '%d'\n", s1[x] , s2[x]);
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
/*
int	ft_check_str(char *str, t_data *data, int neg)
{
	int	len;

	len = 0;
	while (str[len] >= '0' && str[len] <= '9')
		len++;
//	printf("len :%d\t", len);
//	printf("str: %s\n", str);
//	printf("cmp_min(.2147483647.,str): %d\n", ft_strcmp("2147483647", str));
	if (len > 10)
		ft_exit("Error: out of integer range!!\n", data);
	else if (len < 10)
		return (len);
	if (neg)
	{
		if (ft_strcmp("2147483648", str) == 0 || ft_strcmp("2147483647", str) >= 0)
			return (len);
		ft_exit("Error: num < -2147483648\n\n", data);
	}
	else
	{
		if (ft_strcmp("2147483647", str) < 0)
			ft_exit("Error: num > 2147483647\n\n", data);
	}
	return (len);
}
*/
void	ft_add_num(long int tot, t_list **head, t_data *data)
{
	ft_check_num(tot, head, data);
//	printf("\n\tft_add_num - start\n");
	//while (data->stack_a != NULL)
	//	data->stack_a = data->stack_a->next;
//	printf("pre head: %p\t", data->head);
//	printf("pre *head: %p\n", *data->head);
//	printf("pre tail: %p\t", data->tail);
//	printf("pre *tail: %p\n", *data->tail);
	t_list *new;
	t_list *tmp;
	
//	if (data->tail != NULL)
//		new = *data->tail;
	new = (t_list *)malloc(sizeof(t_list) * 1);
	new->num = tot;
//		printf("\nstack[]= %d\n", new->num);
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
/*	
	if (*head == NULL)
	{
		*head = new;
	//	data->tail = new;
	}
	else 
	{
		tmp = *head;
		while (tmp != NULL)
		{
			tmp = tmp->next;
		}
		tmp = new;
	}
	//	data->tail->next = new;
	//	data->tail = new;
//	}
*/
//	new->num = tot;
//		printf("\nstack[]= %d\n", new->num);
//	new->next = NULL;

//	data->tail = new->next;
	
	//new = &data->tail;
	
//	data->tail = new->next;
//	printf("tail: %p\n", data->tail);
//	if (*data->tail != NULL)
//		new = *data->tail;

		//*data->tail = new;
//	*data->tail->next = new;
//	*data->tail = new->next;

//	printf("\tpost tail: %p\n", data->tail);
//	printf("\tpost head: %p\n", data->head);
	//data->head = &stack;
//	printf("\tft_add_data - end\n");
}

void	ft_split_str(char *str, t_data *data)
{
	long int	tot;
	int	neg;
//	int	len;

//	printf("str: %s\t", str);
	
	while (*str)
	{
		neg = 0;
		tot = 0;
	//	len = 0;	
		while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r' || *str == ' ')
			str++;
		if (*str == '-' && *str++)
			neg++;
		else if (*str == '+')
			str++;
		if ((*str < '0' || *str > '9') && *str != '\0')
			ft_exit("Error\n", data);
	//	len = ft_check_str(str, data, neg);
		while (*str >= '0' && *str <= '9')
			tot = tot * 10 + *str++ - 48;
		if (*str != '\0' && !(*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r' || *str == ' '))
			ft_exit("Error\n", data);
//		printf("pos: %d\t", tot);
		if (neg)
			tot *= -1;
	//	printf("neg: %d\n", tot);
	//	if (len)
	//	if ()
		ft_add_num(tot, data->head, data);
		//ft_add_data(data, tot);
	}
	return ;
}
/*
void    ft_print_ops(t_ops **head)
{
	printf("\n\tft_print_ops - start\n");
	t_ops *stack;
	
//printf("print head: %p\n", head);
	stack = *head;
//	printf("head[0]= %d\n", (*head)->num);
	 while (stack != NULL)
	{
		printf("stack[]= %s\n", stack->op);
		stack = stack->next;
	}
}
*/
void    ft_print_stack(t_list **head)
{
	printf("\n\tft_print_stack - start\n");
	t_list *stack;
	
//printf("print head: %p\n", head);
	stack = *head;
//	printf("head[0]= %d\n", (*head)->num);
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
/*	while (x < ac)
	{
	  //  printf("%d\t", x);
		stack->num = ft_atoi(av[x], data);       
		stack->next = (t_list *)malloc(sizeof(t_list) * 1);
		if (x == ac)
			break ;
		stack = stack->next;
		x++;
	}
	stack->next = NULL;
	stack = NULL;
*/	
}
/*
void	ft_buf_to_ops(char *buf, t_data *data)
{
	printf("\tft_buf_to_ops\n");
	return;
	int		x;
	int		y;
	t_ops	*tmp;

	x = 0;
	y = 0;
	
	//tmp->op = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 1));
	tmp = *data->ops;
	while (tmp)
		tmp = tmp->next;
	tmp->op = buf;
	tmp->next = NULL;
//	while ()
//	printf("x: %d\n", x);
//	printf("x+y: %d\n", x + y);
	
	//return (tmp);

}
*/
char	*ft_buf_to_txt(char *buf, char *txt)
{
	int		x;
	int		y;
	char	*tmp;

	x = 0;
	y = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(txt) + 1));
	while (txt && txt[x])
	{
		tmp[x] = txt[x];
		x++;
	}
//	printf("x: %d\n", x);
//	printf("x+y: %d\n", x + y);
	while (buf && buf[y])
	{
		tmp[x + y] = buf[y];
		y++;
	}
	tmp[x + y] = '\0';
//	printf("tmp: %s\n", tmp);
	free(txt);
	return (tmp);

}

void	ft_check_buf(char *buf, int r, t_data *data)
{
	if (buf[r - 1] != '\n')
		ft_exit("Error1: wrong instruction!\n", data);
//	if (r > 1)
//		buf[r - 1] = '\0';
//	printf("%d\n", ft_strcmp("sa", buf));
	if (ft_strcmp("sa", buf) != 0 && ft_strcmp("sb", buf) != 0 && ft_strcmp("ss", buf) != 0
		&& ft_strcmp("pa", buf) != 0 && ft_strcmp("pb", buf) != 0
		&& ft_strcmp("ra", buf) != 0 && ft_strcmp("rb", buf) != 0 && ft_strcmp("rr", buf) != 0
		&& ft_strcmp("rra", buf) != 0 && ft_strcmp("rrb", buf) != 0 && ft_strcmp("rrr", buf) != 0)
		ft_exit("Error2: wrong instruction!\n", data);
		//printf("Error2: wrong instruction!\n");

}

void	ft_read_instr(t_data *data)
{
	char	*buf;
	int		r;
//	char *txt;
//	data->ops = (char **)malloc(sizeof(char *) * 1);
	buf = (char *)malloc(sizeof(char) * 5);
	buf[4] = '\0';
	r = 1;
	while (r)
	{
		r = read(0, buf, 4);
	//	printf("r:%d\n", r);
		if (buf[0] == '\n')
			break ;
		ft_check_buf(buf, r, data);
		
	//	printf("buf:%s\n", buf);
	//	printf("%d\n", ft_strcmp("\n", buf));
	//	if (ft_strcmp("\n", buf) == 10)
	//		break ;
		data->txt = ft_buf_to_txt(buf, data->txt);
	//	ft_buf_to_ops(buf, data);
		buf[0] = '\0';
	}
	printf("-%s-\n", data->txt);
	free(buf);
}

void	ft_move_stack(char *op, t_data *data)
{
//	printf("cmp-rra : %d\n", ft_strcmp("rra", op));
//	printf("cmp-ra : %d\n", ft_strcmp("ra", op));
	int	len;

	len = ft_strlen(op);
	if (len == 2)
	{
		if (ft_strcmp("sa", op) == 0)
			ft_swap(data->head);
		else if (ft_strcmp("sb", op) == 0)
			ft_swap(data->b_head);
		else if (ft_strcmp("ss", op) == 0)
		{
			ft_swap(data->head);
			ft_swap(data->b_head);
		}
		else if (ft_strcmp("pa", op) == 0 && (*data->b_head))
			ft_push(data->b_head, data->head); //ft_push((*data->b_head)->num, data->head);
		else if (ft_strcmp("pb", op) == 0 && (*data->head))
			ft_push(data->head, data->b_head); //ft_push((*data->head)->num, data->b_head);
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
	else
	{
		if (ft_strcmp("rra", op) == 0)
			ft_rev_rot(data->head);
		else if (ft_strcmp("rrb", op) == 0)
			ft_rev_rot(data->b_head);
		else if (ft_strcmp("rrr", op) == 0)
		{
			ft_rev_rot(data->head);
			ft_rev_rot(data->b_head);
		}
	}
}

void	ft_make_instr(t_data *data)
{
	char	*op;
	int		x;
	int		y;

	y = 0;
	if (!data->txt)
		return ;
	op = (char *)malloc(sizeof(char) * 4);
	op[3] = '\0';
	while (data->txt[y])
	{
		x = -1;
		while (op[++x])
			op[x] = '\0';
		x = 0;
	//	op[x] = '\0';
	//	op = NULL;
		while (data->txt[y] != '\n')
		{
			op[x] = data->txt[y];
			x++;
			y++;
		}
		op[x] = '\0';
		y++;
		if (x)
			ft_move_stack(op, data);
			//printf("%s\n", op);
		
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

//	data.len = ac - 1;
	
	if (ac == 1)
	{
		ft_write("Error: invalid args!\n");
		return (0);
	}
	data.head = (t_list **)malloc(sizeof(t_list *) * 1);
	data.b_head = (t_list **)malloc(sizeof(t_list *) * 1);
//	data.ops = (t_ops **)malloc(sizeof(t_ops *) * 1);
//	data.tail = (t_list **)malloc(sizeof(t_list *) * 1);
	*data.head = NULL;
	*data.b_head = NULL;
//	*data.ops = NULL;
//	data.tail = NULL;

//	printf("main head: %p\n", data.head);
//	data.stack_a = *data.head;
	ft_to_stack(av, ac, &data);
 //   ft_print_stack(data.stack_a);
	ft_print_stack(data.head);
	ft_print_stack(data.b_head);
	
	ft_read_instr(&data);
//printf("ops: %s\n", data.txt);
		
	ft_make_instr(&data);
	ft_print_stack(data.b_head);
	ft_print_stack(data.head);
	ft_check_sort(&data);
	
	
	ft_exit("", &data);
	
}