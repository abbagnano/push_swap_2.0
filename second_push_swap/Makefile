OUT2	=	push_swap
OUT1	=	checker
CFLAGS	=	-Wall -Wextra -Werror
OBJS2	=	ft_move_stack.o \
			push_swap.o \
			utils_new_sort.o \
			utils_sort_pos.o \
			utils_push_swap.o \
			utils_moves.o \
			utils_moves2.o \
			utils_norm.o \
			ft_clean_stack.o \
			ft_subseq.o \
			ft_best_pa.o \
			ft_calc.o
OBJS_B	=	checker.o \
			ft_move_stack.o \
			ft_read_ops.o \
			utils_norm.o \
			utils_moves.o \
			utils_moves2.o \
			utils_push_swap.o \
			utils_read.o \
			ft_make_ops.o \



all		:	$(OUT2)

bonus	:	$(OUT1) $(OUT2)

$(OUT2)	:	$(OBJS2)
	gcc $(CFLAGS) $^ -o $@

$(OUT1)	:	$(OBJS_B)
	gcc $(CFLAGS) $^ -o $@

%.o		:	%.c
	gcc -c $(CFLAGS) $^

clean	:
	rm -rf $(OBJS2) $(ARGV) $(OBJS_B)

fclean	:	clean
	rm -rf $(OUT2) $(OUT1)

re		:	clean	fclean	all

PHONY	:	all bonus clean fclean re