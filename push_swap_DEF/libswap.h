/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libswap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:21:44 by fgradia           #+#    #+#             */
/*   Updated: 2021/05/18 14:33:53 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSWAP_H
# define LIBSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	int				num;
	int				pos;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	t_list	**head;
	t_list	**b_head;
	char	*txt;	
	int		len;
	int		min;
	int		max;
	int		ops;
	t_list	*b_tail;
}	t_data;

/*	utils_push_swap.c	*/
int		ft_strlen(char *str);
void	ft_write(char *str);
void	ft_free_stack(t_list **head);
void	ft_exit(char *str, t_data *data);

/*	push_swap.c		->		main	*/
void	ft_check_num(long int tot, t_list **head, t_data *data);
void	ft_add_num(long int tot, t_list **head, t_data *data);
void	ft_split_str(char *str, t_data *data);
void	ft_to_stack(char **av, int ac, t_data *data);

/*	ft_sort_pos.c	*/
void	ft_sort_pushed(t_list **dst_head, t_data *data, int med);
int		ft_find_next_pa(t_list **head, int next);
int		ft_check_pushed(t_list **head, t_data *data);
void	ft_sort_by_pos(t_data *data);

/*	halfing_from_a.c	*/
void	ft_halfing_stack(t_list **head, t_list **dst_head,
			int min_pos, t_data *data);
void	ft_halfing_stack_2(t_list **head, t_list **dst_head,
			int min_pos, t_data *data);
void	ft_start_halfing(t_list **head, t_list **dst_head, t_data *data);
void	ft_start_halfing_2(t_list **head, t_list **dst_head, t_data *data);
void	ft_way_back(t_list **head, int *back, t_data *data);

/*	halfing_from_b.c	*/
void	ft_push_back(t_data *data);
void	ft_halfing_stack_rev(t_list **head, t_list **dst_head,
			int min_pos, t_data *data);
void	ft_halfing_back(t_list **head, t_list **dst_head, t_data *data);
void	ft_find_next(t_data *data, int *x);
void	ft_way_back_b(t_list **head, int *back, t_data *data);

/*	utils_new_sort.c	*/
void	ft_init_pos(t_list **head);
void	ft_check_pos(t_data *data, int num);
void	ft_get_range(t_data *data);
int		ft_find_lower(t_list **head, int min);
void	ft_put_lower_at_head(t_list **head, t_data *data, int min);

/*	ft_move_stack.c		*/
int		ft_swap(t_list **head);
void	ft_push(t_list **topush, t_list **head);
int		ft_rotate(t_list **head);
int		ft_rev_rot(t_list **head);

/*	utils_sort_pos.c	*/
int		ft_listlen(t_list **head, int *min_pos);
t_list	*ft_get_tail(t_list **head, t_list *tail);
int		ft_keep_swapping(t_list **head, t_data *data);

/*	utils_norm.c		*/
void	ft_ra(t_list **dst_head, t_data *data);
void	ft_rb(t_list **dst_head, t_data *data);
void	ft_sa(t_list **dst_head, t_data *data);
void	ft_sb(t_list **dst_head, t_data *data);
void	ft_pb(t_list **head, t_list **dst_head, t_data *data);

/*	utils_norm_2.c		*/
void	ft_rra(t_list **dst_head, t_data *data);
void	ft_pa(t_list **head, t_list **dst_head, t_data *data);
void	ft_backing(t_data *data);
int		ft_isspace(char c);
void	ft_get_sign(char c, int *neg);

/*	utils_halfing.c	*/
void	ft_under_med(t_list **head, t_list **dst_head, int med, t_data *data);
void	ft_over_med(t_list **head, int *back, int med, t_data *data);
void	ft_over_med_b(t_list **head, t_list **dst_head, int med, t_data *data);
void	ft_under_med_b(t_list **head, int *back, int med, t_data *data);
int		ft_save_line(t_data *data, int *x);

#endif
