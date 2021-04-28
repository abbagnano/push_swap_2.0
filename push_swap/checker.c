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

void    ft_free_stack(t_list *stack, t_data *data)
{	printf("\t\tfreee\n");

	int x;
	x = 0;
	printf("data_ac= %d\n", data->ac);
	data->ac--;
//	while (stack->next != NULL && printf("qwe\n"))
	while (x < data->ac)
		stack = stack->next;
	free(stack);//->next);
	
}

void	ft_exit(char *str, t_data *data)
{
	ft_write(str);
	data->ac--;
	while (data->ac)
		ft_free_stack(&data->stack_a, data);
 //   (void)data;
//	free(data->stack_a);
//	free(*data->stack_a.next);
//	free(*data->stack_b);
//	free(data->stack_a);
//	free(data->stack_b);
//	free(data);
}

int		ft_atoi(char *str, t_data *data)
{
	int	tot;
	int	neg;

	tot = 0;
	neg = 0;
	if (*str == '-' && *str++)
		neg++;
	if (*str < '0' || *str > '9')
		ft_exit("Error\n", data);
	while (*str >= '0' && *str <= '9')
		tot = tot * 10 + *str++ - 48;
	if (neg)
		tot *= -1;
//	printf("tot: %d\n", tot);
	return (tot);
}

void    ft_print_stack(t_list *stack)
{
	 while (stack->next != NULL)
	{
		printf("\nstack[]= %d\n", stack->num);
		if (!(stack->next) && printf("qwe\n"))
			break ;
		stack = stack->next;
	}
}

void    ft_to_stack(t_list *stack, char **av, int ac, t_data *data)
{
	int x;

	x = 1;
	while (x < ac)
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
//	stack = NULL;
}

int main(int ac, char **av)
{
	t_data	data;

	data.ac = ac;
	
	if (ac < 2)
	{
		ft_write("Error: invalid args!\n");
		return (0);
	}
	ft_to_stack(&data.stack_a, av, ac, &data);
    ft_print_stack(&data.stack_a);
	ft_exit("", &data);
//		char buf[10];
//	read(0, &buf, 9);
}