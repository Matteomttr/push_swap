NAME= push_swap.a

CC= cc
CFLAGS= -Wall -Werror -Wextra

AR= ar
ARFLAGS= rsc

SRCS=	
OBJS= 	

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "Archive created successfully!"

%.o: %.c	
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "Object successfully deleted!"
	
fclean: clean
	@rm -f $(NAME)
	@echo "Archive successfully deleted!"

re: fclean all

.PHONY: all clean fclean re