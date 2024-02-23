CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

OBJ = $(SRCS:.c=.o)

SRCS =	memory/ft_bzero.c \
		check/ft_isalnum.c \
		check/ft_isalpha.c \
		check/ft_isascii.c \
		check/ft_isdigit.c \
		check/ft_isprint.c \
		memory/ft_memcpy.c \
		memory/ft_memset.c \
		string/ft_strchr.c \
		string/ft_strlcpy.c \
		string/ft_strlen.c \
		string/ft_strrchr.c \
		string/ft_tolower.c \
		string/ft_toupper.c \
		string/ft_strncmp.c \
		memory/ft_memchr.c \
		memory/ft_memcmp.c \
		string/ft_strdup.c \
		memory/ft_calloc.c \
		memory/ft_memmove.c \
		string/ft_strlcat.c \
		conversion/ft_atoi.c \
		conversion/ft_atol.c \
		string/ft_strnstr.c \
		string/ft_substr.c \
		string/ft_strjoin.c \
		string/ft_strtrim.c \
		stdout/ft_putchar_fd.c \
		stdout/ft_putstr_fd.c \
		stdout/ft_putendl_fd.c \
		stdout/ft_putnbr_fd.c \
		string/ft_strmapi.c \
		string/ft_split.c \
		conversion/ft_itoa.c \
		string/ft_striteri.c \
		linked_list/ft_lstnew.c \
		linked_list/ft_lstsize.c \
		linked_list/ft_lstlast.c \
		linked_list/ft_lstadd_back.c \
		linked_list/ft_lstdelone.c \
		linked_list/ft_lstclear.c \
		linked_list/ft_lstiter.c \
		linked_list/ft_lstmap.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_putcharl.c \
		ft_printf/ft_putnbrl.c \
		ft_printf/ft_putnbr_basel.c \
		ft_printf/ft_putstrlen.c \
		ft_printf/ft_putunbrl.c \
		get_next_line/get_next_line_bonus.c \
		get_next_line/get_next_line_utils_bonus.c

all: $(NAME)

$(NAME): $(OBJ)
	ar crs libft.a $(OBJ)

%.o: %.c $(SRCS)
	${CC} ${CFLAGS} -o $@ -c $<

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJ) 

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf libft.a
	
re: fclean all

.PHONY: all clean fclean re