NAME		=	push_swap
NAME_BONUS	=	checker

SRCS		=	main.c			push_swap.c				sorting.c			movement.c \
				sorting_1.c		find_actions.c			modes.c					stack_double.c

SRCS_BONUS	=	$(BONUS_DIR)/main.c					$(BONUS_DIR)/checker.c		$(BONUS_DIR)/stack_double.c \
				$(BONUS_DIR)/movement.c	


LIB_DIR 	= ./libft
BONUS_DIR	= ./SRC_BONUS
HEADER 		= ./push_swap.h
HEADER_BON		= $(BONUS_DIR)/checker.h

OBJS		=	$(patsubst %.c,%.o,$(SRCS))
OBJS_BONUS	=	$(patsubst %.c,%.o,$(SRCS_BONUS))

OPTFLAGS	=	-O2
CFLAGS		=	-Wall -Wextra -Werror -g

all:		$(NAME)

bonus:		$(NAME_BONUS)

$(NAME):	$(OBJS)
			@make -C $(LIB_DIR)
			gcc $(LIB_DIR)/libft.a $(OBJS) -o $(NAME)
			@clear
			@echo all done, my Master!

$(NAME_BONUS):  $(OBJS_BONUS)
				@make -C $(LIB_DIR)
				gcc $(LIB_DIR)/libft.a $(OBJS_BONUS) -o $(NAME_BONUS)
				@clear
				@echo all done, my Master!

%.o: 		%.c $(HEADER) ./libft/*.c
			gcc $(CFLAGS) $(OPTFLAGS) -I $(HEADER) -c $< -o $@

clean:
			@rm -f $(OBJS) $(OBJS_BONUS)
			@make clean -C $(LIB_DIR)
			@clear
			@echo  files destroyed, my Master!

fclean:		clean
			@rm -f $(NAME) $(NAME_BONUS)
			@make fclean -C $(LIB_DIR)
			@clear
			@echo all terminated, my Master!
			

re:			fclean all bonus

.PHONY:		all clean fclean re bonus
