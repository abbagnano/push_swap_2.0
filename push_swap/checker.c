#include "libswap.h"

int		ft_strlen(char *str)
{
	int x;

	x = 0;
	while (str[x])
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
	ft_write(str);
//	ft_free_stack(&data->stack_a, data);
    (void)data;
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
void	ft_check_num(int tot, t_data *data)
{
	(void)tot;
	(void)data;
//	if (tot )
}

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

void	ft_add_num(int tot, t_data *data)
{
//	ft_check_num(tot, data);
//	printf("\n\tft_add_num - start\n");
	//while (data->stack_a != NULL)
	//	data->stack_a = data->stack_a->next;
//	printf("pre head: %p\t", data->head);
//	printf("pre *head: %p\n", *data->head);
//	printf("pre tail: %p\t", data->tail);
//	printf("pre *tail: %p\n", *data->tail);
	t_list *new;

//	if (data->tail != NULL)
//		new = *data->tail;
	new = (t_list *)malloc(sizeof(t_list) * 1);
	
	if (*data->head == NULL)
	{
		*data->head = new;
		data->tail = new;
	}
	else 
	{
		data->tail->next = new;
		data->tail = new;
	}

	new->num = tot;
//		printf("\nstack[]= %d\n", new->num);
	new->next = NULL;

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
	int	tot;
	int	neg;
	int	len;

//	printf("str: %s\t", str);
	
	while (*str)
	{
		neg = 0;
		tot = 0;
		len = 0;	
		while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r' || *str == ' ')
			str++;
		if (*str == '-' && *str++)
			neg++;
		if ((*str < '0' || *str > '9') && *str != '\0')
			ft_exit("Error\n", data);
		len = ft_check_str(str, data, neg);
		while (*str >= '0' && *str <= '9')
			tot = tot * 10 + *str++ - 48;
		if (*str != '\0' && !(*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r' || *str == ' '))
			ft_exit("Error\n", data);
//		printf("pos: %d\t", tot);
		if (neg)
			tot *= -1;
//		printf("neg: %d\n", tot);
		if (len)
			ft_add_num(tot, data);
		//ft_add_data(data, tot);
	}
	return ;
}

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

int main(int ac, char **av)
{
	t_data	data;

	data.len = ac - 1;
	
	if (ac == 1)
	{
		ft_write("Error: invalid args!\n");
		return (0);
	}
	data.head = (t_list **)malloc(sizeof(t_list *) * 1);
//	data.tail = (t_list **)malloc(sizeof(t_list *) * 1);
	*data.head = NULL;
	data.tail = NULL;

//	printf("main head: %p\n", data.head);
//	data.stack_a = *data.head;
	ft_to_stack(av, ac, &data);
 //   ft_print_stack(data.stack_a);
	ft_print_stack(data.head);
	ft_exit("", &data);
//		char buf[10];
//	read(0, &buf, 9);
}