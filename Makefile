NAME= push_swap.a

CC= cc
CFLAGS= -Wall -Werror -Wextra

AR= ar
ARFLAGS= rsc

SRC_DIR= src
OBJ_DIR= obj

SRCS=	
OBJS= 	

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re