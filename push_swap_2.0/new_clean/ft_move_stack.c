#include "libswap.h"

int	ft_swap(t_list **head) //t_data *data)
{
//	printf("\tft_swapping\n");
//	int	tmp;
t_list	*old_first;
t_list	*old_second;
//ft_print_stack(head);
	if (!(head) || !(*head) || !((*head)->next))
	{
		//printf("qwe\n");
		return (0);
	}
	old_first = *head;
//	old_first->next = (*head)->next->next;
	old_second = (*head)->next;
	old_first->next = old_second->next;	
	old_second->next = old_first;//*head;




//	tmp_next->next = tmp;
	*head = old_second;
	//(*head)->next = tmp;
//	exit(0);
//	ft_print_stack(head);
//	tmp = (*head)->num;
//	(*head)->num = (*head)->next->num;
//	(*head)->next->num = tmp;
//ft_print_stack(head);
	return (1);
}

void	ft_push(t_list **topush, t_list **head)
{
	//printf("\tft_pushing\n");
	//t_list *new;
	t_list *nodetopush;

	nodetopush = *topush;
	*topush = (*topush)->next;
	nodetopush->next = *head;
	*head = nodetopush;



/*
	new = (t_list *)malloc(sizeof(t_list) * 1);
	new->next = *head;
	new->num = (*topush)->num;
	*head = new;
	new = *topush;
	(*topush) = (*topush)->next;
	free(new);
	ft_print_stack(head);*/
}

int	ft_rotate(t_list **head)
{
//	printf("\tft_rotating\n");
//	t_list	*old_first;
//	t_list	*old_last;
//	t_list	*new;
//	int		num;

	if (!(head) || !(*head) || !(*head)->next)
	{
		//printf("qwe\n");
		return (0);
	}
	t_list *last;
	t_list *tmp;

	
	last = *head;
	tmp = (*head)->next;
	//tmp->next = NULL;
	while (last->next)
		last = last->next;
	last->next = *head; //tmp;
	last->next->next = NULL;
	*head = tmp;

	return (1);

/*	while (last->next->next)			/// fa rev_rot!!!
		last = last->next;
	tmp = last->next;
//	printf("\t\tnewnum: %d\n", tmp->num);
	//tmp->next = *head;
	last->next = NULL;
	last = *head;
	tmp->next = last;
	*head = tmp;
*/	//(*head)->next = last;
//	printf("\t\tnewnum: %d\n", (*head)->num);
//printf("stack post rotate\n");
//	ft_print_stack(head);
//	last->next = NULL;
//	tmp = *head;
//	*head = last;
//	(*head)->next = tmp;
//	old_last = (t_list *)malloc(sizeof(t_list) * 1);
//	old_last = *head;
//	while (old_last->next->next != NULL)
//		old_last = old_last->next;
//		printf("\t\tnum: %d\n", old_last->num);
	
//	old_first = *head;
//	num = (*head)->num;
//	*head = (*head)->next;
//	free(old_first);
//	new = *head;
//	while (new->next != NULL)
//		new = new->next;
//	old_first->next = NULL;
//	*head = new;

//	new = (t_list *)malloc(sizeof(t_list) * 1);
//	new = old_last->next;
//	new->next = (t_list *)malloc(sizeof(t_list) * 1);
//	new->next = *head;
//	printf("\t\tnewnum: %d\n", new->num);
//	old_last->next = NULL;
//	free(old_last);
	
//	*head = new;

//	new = new->next;
//	new->num = num;
//	new->next = NULL;
//	(void)data;
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
//ft_print_stack(head);
}

int	ft_rev_rot(t_list **head)
{
	//printf("\tft_rev_rotating\n");
	t_list	*last;
	t_list	*tmp;

	if (!(head) || !(*head) || !((*head)->next))
	{
		//printf("qwe\n");
		return (0);
	}
	last = *head;
	while (last->next->next)
		last = last->next;
//	printf("last: %d\n", last->num);

	tmp = last->next;
	last->next = NULL;
	tmp->next = *head;
	*head = tmp; 

	return (1);

/*	t_list	*tmp;
	t_list	*new;
	int		num;

	if (!(head) || !(*head))// || !((*head)->next))
	{
		//printf("qwe\n");
		return ;
	}
	tmp = *head;
//	printf("%d\n", (*head)->num);
//	printf("%d\n", tmp->num);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
//	printf("%d\n", tmp->num);
	num = tmp->next->num;
	tmp->next = NULL;
	free(tmp->next);
	new = (t_list *)malloc(sizeof(t_list) * 1);
	new->num = num;
	new->next = *head;
	*head = new;
*/
}