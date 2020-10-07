NAME = seidel
SRCS = srcs/main.c \
	srcs/matrix_operations.c srcs/seidel.c srcs/write_read_matrix.c
OBJ = $(SRCS:.c=.o)
# LIBDIR = libft/
# LIBNAME = libft/libft.a
# CFLAGS = -Wall -Wextra -Werror -I includes/
CFLAGS = -I includes/

all: $(NAME)

$(OBJ): %.o: %.c
	gcc -c $(CFLAGS) $< -o $@

$(LIBNAME):
	@make -C

$(NAME): $(OBJ)
	gcc $(CFLAGS) \
	$(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)
	@echo OBJECTS FILES HAVE BEEN DELETED.

fclean: clean
	@/bin/rm -f $(NAME)
	@echo OBJECT FILES AND EXECUTABLE HAVE BEEN DELETED.

re: fclean all