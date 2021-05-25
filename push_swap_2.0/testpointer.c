#include <stdio.h>

void	ft_4_pointer(char **s1, char **s2)
{
	int x = 0;

	while ((*s1)[x] != '\0')
		x++;
}

void	ft_3_pointer(char **s1, char **s2)
{
	while (**s1)
		(*s1)++;
}

void	ft_2_pointer(char **s1, char **s2)
{
	char *tmp;

	tmp = *s1;
	while (*tmp)
		tmp++;
}

void	ft_pointer(char *s1, char *s2)
{
	while (*s1)
		s1++;
}

int main(int ac, char **av)
{
	printf("s1: %s\t s2: %s\n", av[1], av[2]);
    ft_pointer(av[1], av[2]);
	printf("\n\tpost-pointer\ns1: %s\t s2: %s\n", av[1], av[2]);
	printf("\tpost-pointer\ns1: %p\t s2: %p\n", &av[1], &av[2]);

	ft_2_pointer(&av[1], &av[2]);
	printf("\n\tpost-2_p\ns1: %s\t s2: %s\n", av[1], av[2]);
	printf("\tpost-2_p\ns1: %p\t s2: %p\n", &av[1], &av[2]);

	ft_4_pointer(&av[1], &av[2]);
	printf("\n\tpost-4_p\ns1: %s\t s2: %s\n", av[1], av[2]);
    printf("\tpost-4_p\ns1: %p\t s2: %p\n", &av[1], &av[2]);

	ft_3_pointer(&av[1], &av[2]);
	printf("\n\tpost-3_p\ns1: %s\t s2: %s\n", av[1], av[2]);
    printf("\tpost-3_p\ns1: %p\t s2: %p\n", &av[1], &av[2]);
    return 0;
}