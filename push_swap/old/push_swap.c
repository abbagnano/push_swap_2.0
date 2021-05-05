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
//									printf("exiting.. check leaks!!\n");
//									char buf[10];			//	per i leaks!!
//									read(0, &buf, 9);
	
	exit (0);
//	free(data->stack_a);
//	free(*data->stack_a.next);
//	free(*data->stack_b);
//	free(data->stack_a);
//	free(data->stack_b);
//	free(data);
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
//	printf("cmp_char: '%c' - '%c'\n", s1[x] , s2[x]);
//	printf("cmp_int: '%d' - '%d'\n", s1[x] , s2[x]);
	return (s1[x] - s2[x]);
}

void	ft_check_num(long int tot, t_data *data)
{
	t_list *tmp;

	tmp = *data->head;
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
	ft_check_num(tot, data);
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
}

int	ft_check_swap(t_data *data)
{
	int		min;
	t_list	*tmp;

	
	tmp = *data->head;
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

//void	ft_push_swap(t_data *data)
//{
//	printf("\n\tft_push_swap!\n");
//	int	min;
//	int	max;
/*	int		flag;
	t_list	*tmp;
	t_list	*tail;
	t_list	*count;

	flag = 1;
	tmp = *data->head;
	count = *data->head;
	while (tmp != NULL || ft_check_swap(data) == 0)
	{
		tmp = *data->head;
		while (tmp->next && tmp->num < tmp->next->num)
			tmp = tmp->next;
		if (tmp->next && tmp->num > tmp->next->num)
	}*/
/*	while (tmp != NULL)
	{
		if (flag != 0)
		{
		//	printf("\nxxxx\n");
			tmp = *data->head;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tail = tmp;
			tmp = *data->head;
			count = *data->head;
		}
	//	printf("\nxxxx\n");
		
//		printf("tail->num : %d\n", tail->num);
		flag = 0;
	//	if (tmp->num > tail->num && flag++)
	//		ft_rev_rot(data->head);
		while (tmp->num < tmp->next->num)// && count != NULL)
		{
	//		printf("tmp->num: %d\n", tmp->num);
	//	printf("tmp->next->num: %d\n", tmp->next->num);
			ft_rotate(data->head);
			ft_write("ra\n");
			tmp = *data->head;
			ft_print_stack(data->head);
		//	count = count->next;
			
		}
		if (tmp->num > tmp->next->num)
		{
			printf("\nxxxx\n");
			printf("tmp->num: %d\n", tmp->num);
		printf("tmp->next->num: %d\n", tmp->next->num);
			ft_swap(data->head);
			flag++;
			ft_write("sa\n");
			ft_print_stack(data->head);
		}
		if (!count)
			break ;
		if (ft_check_swap(data))
			break ;	
	//	if (flag)
	//		continue ;
		//tmp = tmp->next;
	//	printf("\nxxxx\n");
	//	ft_rotate(data->head);
	//	ft_write("ra\n");
	}*/
//}

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
//	*data.ops = NULL;
//	data.tail = NULL;

//	printf("main head: %p\n", data.head);
//	data.stack_a = *data.head;
	ft_to_stack(av, ac, &data);
 //   ft_print_stack(data.stack_a);

//	ft_print_stack(data.head);
	
//	ft_print_stack(data.b_head);
	ft_get_range(&data);
	ft_push_swap(&data);
	ft_print_stack(data.head);
	ft_exit("", &data);
}