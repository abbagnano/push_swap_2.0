OUT2	=	push_swap
CFLAGS	=	-Wall -Wextra -Werror
OBJS2	=	ft_move_stack.o \
			push_swap.o \
			utils_new_sort.o \
			ft_sort_pos.o \
			utils_sort_pos.o \
			halfing_from_a.o \
			utils_push_swap.o \
			halfing_from_b.o \
			utils_norm.o \
			utils_norm_2.o \
			utils_halfing.o


all		:	$(OUT2) 

$(OUT2)	:	$(OBJS2)
	gcc $(CFLAGS) $^ -o $@

%.o		:	%.c
	gcc -c $(CFLAGS) $^

clean	:
	rm -rf $(OBJS2) $(ARGV) 

fclean	:	clean
	rm -rf $(OUT2)

re		:	clean	fclean	all

PHONY	:	all clean fclean re