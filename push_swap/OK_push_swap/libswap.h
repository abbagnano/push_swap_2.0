/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libswap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:21:44 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/03 12:21:49 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSWAP_H
# define LIBSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct  s_list
{
	int num;
	struct s_list *next;
}               t_list;

typedef struct s_data
{
	t_list	**head;
//	t_list	*stack_a;
//	t_list	*tail;
	t_list	**b_head;
//	t_list	*b_tail;
	char	*txt;	
//	int		len;
//	int		min;
//	int		max;
	t_list	*lowest;
	t_list	*maxest;
	t_list	*start;
	t_list	*tail;
}				t_data;

typedef struct  s_flags
{
	int	s;
	int	r;
	int	p;
}               t_flags;

void	ft_swap(t_list **head);
void	ft_push(t_list **topush, t_list **head);
void	ft_rotate(t_list **head);
void	ft_rev_rot(t_list **head);

void	ft_add_num(long int tot, t_list **head, t_data *data);

void	ft_get_range(t_data *data);
void	ft_push_swap(t_data *data);

int		ft_check_swap(t_list **head, t_data *data);
void    ft_print_stack(t_list **head);

#endif


/*
	checker:
	clear && gcc  ft_move_stack.c checker.c && ./a.out 2 1 3 4

	push swap:
	clear && gcc  ft_move_stack.c ft_try_swap.c push_swap.c && ./a.out 2 1 3 4


clear && gcc -Wall -Wextra *.c -fsanitize=address -g3 && ./a.out  66 -55555 44 88 99 6


clear && gcc -Wall -Wextra *.c  && ./a.out  66 -55555 44 88 99 6

*/
