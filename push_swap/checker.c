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
void	ft_add_num(int tot, t_data *data)
{
	printf("\n\tft_add_num - start\n");
	//while (data->stack_a != NULL)
	//	data->stack_a = data->stack_a->next;
	printf("pre head: %p\t", data->head);
	printf("pre *head: %p\n", *data->head);
	printf("pre tail: %p\t", data->tail);
//	printf("pre *tail: %p\n", *data->tail);
	t_list *new;

//	if (data->tail != NULL)
//		new = *data->tail;
	new = (t_list *)malloc(sizeof(t_list) * 1);
	
	if (*data->head == NULL)
	{
		*data->head = new;
		data->tail = new;
	//	data->tail = &new->next;
	}
	else 
	{
		data->tail->next = new;
		data->tail = new;
	}

	new->num = tot;
		printf("\nstack[]= %d\n", new->num);
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

	printf("\tpost tail: %p\n", data->tail);
	printf("\tpost head: %p\n", data->head);
	//data->head = &stack;
//	printf("\tft_add_data - end\n");
}

void	ft_split_str(char *str, t_data *data)
{
	int	tot;
	int	neg;

	while (*str)
	{
		neg = 0;
		tot = 0;	
		while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r' || *str == ' ')
			str++;
		if (*str == '-' && *str++)
			neg++;
		if (*str < '0' || *str > '9')
			ft_exit("Error\n", data);
		while (*str >= '0' && *str <= '9')
			tot = tot * 10 + *str++ - 48;
		if (neg)
			tot *= -1;
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