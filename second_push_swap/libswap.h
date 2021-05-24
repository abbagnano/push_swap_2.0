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

typedef struct s_ops
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
}	t_ops;

typedef struct s_list
{
	int				num;
	int				pos;
	int				idx;
	int				tot;
	int				flag;
	t_ops			ops;

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
	t_list	*max_idx;
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
int		ft_keep_swapping_pos(t_list **head, t_data *data);
int		ft_keep_swapping(t_list **head, t_data *data);
void	ft_keep_pb(t_data *data, int idx);

/*	utils_moves.c		*/
void	ft_ra(t_list **dst_head, t_data *data);
void	ft_rb(t_list **dst_head, t_data *data);
void	ft_sa(t_list **dst_head, t_data *data);
void	ft_sb(t_list **dst_head, t_data *data);
void	ft_pb(t_list **head, t_list **dst_head, t_data *data);

/*	utils_moves2.c		*/
void	ft_rra(t_list **dst_head, t_data *data);
void	ft_rrb(t_list **dst_head, t_data *data);
void	ft_pa(t_list **head, t_list **dst_head, t_data *data);
void	ft_rr(t_data *data);
void	ft_rrr(t_data *data);

/*	utils_norm.c		*/
void	ft_check_pa(t_data *data);
void	ft_ss(t_data *data);
int		ft_isspace(char c);
void	ft_get_sign(char c, int *neg);

/*	ft_clean_stack.c	*/
int		ft_ops_rra(t_data *data, t_list *tmp_b);
int		ft_ops_ra(t_data *data, t_list *tmp_b);
void	ft_mosse(t_data *data);
void	ft_empty_b(t_data *data);

/*	ft_subseq.c		*/
void	ft_subseq(t_list *tmp);
int		ft_next_idx(t_list *tmp, int max_idx, int max_data);
int		ft_sign_idx(t_data *data, int max_idx, int max_data);
void	ft_check_index(t_data *data);
void	ft_split_seq(t_data *data, int max_data);

/*	ft_best_pa.c	*/
void	ft_put_ra_rrb(t_data *data, t_list *temp_b);
void	ft_put_rb_rra(t_data *data, t_list *temp_b);
void	ft_put_reverse(t_data *data, t_list *temp_b);
void	ft_put_rotate(t_data *data, t_list *temp_b);
void	ft_best_pa(t_data *data);

/*	ft_calc.c		*/
void	ft_sort_five(t_data *data);
void	ft_sort_five2(t_data *data, int min, int max);
void	ft_up_to_five(t_data *data);
int		ft_flagging_tot(int *tot_r, int tot_rr,
			int tot_ra_rrb, int tot_rb_rra);
void	ft_calc(t_data *data);

#endif
