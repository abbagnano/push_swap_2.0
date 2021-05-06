OUT1	=	checker
OUT2	=	push_swap
CFLAGS	=	-Wall -Wextra -Werror
#SRCS1	=	ft_move_stack.c checker.c
#SRCS2	=	ft_move_stack.c ft_try_swap.c push_swap.c
OBJS1	=	ft_move_stack.o checker.o
OBJS2	=	ft_move_stack.o ft_try_swap.o push_swap.o

all		:	$(OUT1) $(OUT2)

$(OUT1)	:	$(OBJS1)
	gcc $(CFLAGS) $^ -o $@

$(OUT2)	:	$(OBJS2)
	gcc $(CFLAGS) $^ -o $@

%.o		:	%.c
	gcc -c $(CFLAGS) $^ 

clean	:
	rm -rf $(OBJS1) $(OBJS2)

fclean	:	clean
	rm -rf $(OUT1) $(OUT2)

re		:	clean	fclean	all

PHONY	:	all clean fclean re