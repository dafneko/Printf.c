NAME = libftprintf.a
HEADERDIR = .
SRC = ft_printf.c utils.c 
CC = cc
CCFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
AR = ar rcs

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $< -I $(HEADERDIR)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:
	all clean fclean re