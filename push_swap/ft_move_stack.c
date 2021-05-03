#include "libswap.h"

void	ft_swap(t_list **head) //t_data *data)
{
	printf("\tft_swapping\n");
	int	tmp;

	if (!(head) || !(*head) || !((*head)->next))
	{
		printf("qwe\n");
		return ;
	}
	tmp = (*head)->num;
	(*head)->num = (*head)->next->num;
	(*head)->next->num = tmp;
}

void	ft_push(t_list **topush, t_list **head)
{
	printf("\tft_pushing\n");
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	new->next = *head;
	new->num = (*topush)->num;
	*head = new;
	new = *topush;
	(*topush) = (*topush)->next;
	free(new);
}

void	ft_rotate(t_list **head, t_list *tail, t_data *data)
{
	printf("\tft_rotating\n");
	t_list	*tmp;
	t_list	*new;
	int		num;

	tmp = *head;
	num = (*head)->num;
	*head = (*head)->next;
	free(tmp);
/*
//////		DA AGGIUNGERE IL VECCHIO DATO ALLA TAIL!!!
*/
//	new = (t_list *)malloc(sizeof(t_list) * 1);
//	new->num = num;
//	new->next = NULL;
	//if (tail == NULL)
	//	tail = new;
//	else 
//	{
//		tail->next = new;
//		tail = new;
//	}	
}