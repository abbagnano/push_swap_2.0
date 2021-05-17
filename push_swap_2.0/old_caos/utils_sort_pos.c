#include "libswap.h"


void	ft_what_next(t_data *data)
{
	printf("ft_what_next- start\n");
	int len;
	int min_pos;

//	(void)data;
		//ft_halfing_back(data->b_head, data->head, data);
	len = ft_listlen(data->b_head, &min_pos);
//	printf("111 ft_keep_sw: %d\n", ft_keep_swapping(head, data));
//	printf("ft_loc_sort: %d\n", ft_check_local_sort(head, min_pos, min_pos + len));
	printf("\n\n\tpost post a:\n");
			ft_print_stack(data->head);
				printf("\tpost post b:\n");
			ft_print_stack(data->b_head);
	printf("len: %d\tmin_pos: %d\n", len, min_pos);
//	if (len < 2)
//		return ;

	exit(0);
}


void	ft_halfing_pushed(t_list **head, t_data *data)
{

	printf("ft_halfing_pushed - start\n");
	int len;
	int min_pos;

	(void)data;

	len = ft_listlen(head, &min_pos);
//	printf("111 ft_keep_sw: %d\n", ft_keep_swapping(head, data));
//	printf("ft_loc_sort: %d\n", ft_check_local_sort(head, min_pos, min_pos + len));
	printf("len: %d\tmin_pos: %d\n", len, min_pos);
//	if (len < 2)
//		return ;

	exit(0);
//	return ;
}