C = clang

NAME = lu

DIR_S = srcs

DIR_O = obj

HEADER = includes

SOURCES =	lu.c \
write_read_matrix.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/header.h
	@mkdir -p obj
	@$(CC) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean re all clean