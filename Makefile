# VARIABLE
NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

# PUSH_SWAP
SRCS = rule_check.c move_elements.c push_swap.c sort_under_5.c utils.c push.c rotate.c swap.c cal_rotate_cnt.c optimal_element.c
SRCS_DIR = srcs/push_swap/
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))

# PUSH_SWAP_BONUS
BONUS_SRCS = checker.c rule_check.c move_elements.c sort_under_5.c utils.c push.c rotate.c swap.c
BONUS_SRCS_DIR = srcs/push_swap/checker/
BONUS_SRCS_PATH = $(addprefix $(BONUS_SRCS_DIR), $(BONUS_SRCS))

# GET_NEXT_LINE
GNL_SRCS = get_next_line.c get_next_line_utils.c
GNL_DIR = srcs/libft/
GNL_PATH = $(addprefix $(GNL_DIR), $(GNL_SRCS))

# LIBFT
LIBFT_DIR = srcs/libft/
LIBFT_A = $(addprefix $(LIBFT_DIR), libft.a)

INCS = includes/
OBJS = $(SRCS_PATH:.c=.o)
BONUS_OBJS = $(BONUS_SRCS_PATH:.c=.o) $(GNL_PATH:.c=.o)

ifdef BONUS
	NAME = $(BONUS_NAME)
	OBJS = $(BONUS_OBJS)
endif

# COMMANDS
%.o : %.c
	@echo "$(YELLOW) *** Generating push_swap objects... *** $(DEFAULT)"
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS) -I $(LIBFT_DIR) -I $(GNL_DIR)

$(NAME) : $(OBJS)
	@echo "$(GREEN) *** Compiling push_swap ... *** $(DEFAULT)"
	make -C srcs/libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A)
	@echo "$(GREEN) *** Compile Done!! *** $(DEFAULT)"

all : $(NAME) 
	@echo "$(GREEN) *** Project Ready! *** $(DEFAULT)"

clean :
	@echo "$(RED) *** Deleting objects... *** $(DEFAULT)"
	$(RM) $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean

fclean : clean
	@echo "$(RED) *** Deleting all... *** $(DEFAULT)"
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(BONUS_NAME)

re :
	make fclean
	make all

bonus :
	make BONUS=1 all

.PHONY : all clean fclean re

# COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m