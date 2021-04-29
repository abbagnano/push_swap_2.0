#ifndef LIBSWAP_H
# define LIBSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct  s_list
{
	int num;
	struct s_list *next;
}               t_list;

typedef struct s_data
{
	t_list	**head;
//	t_list	*stack_a;
//	t_list	*stack_b;
	t_list	*tail;
	int		len;
}				t_data;

#endif



/*

clear && gcc -Wall -Wextra *.c -fsanitize=address -g3 && ./a.out  66 -55555 44 88 99 6


clear && gcc -Wall -Wextra *.c  && ./a.out  66 -55555 44 88 99 6

*/