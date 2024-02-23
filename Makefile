CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

NAME_CLIENT = client

NAME_SERVER = server

SRC_SERVER = server.c
OBJ_SERVER = server.o

SRC_CLIENT = client.c
OBJ_CLIENT = client.o

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a
LDFLAGS = -L $(LIBFT_DIR) -lft

INCLUDE = -I $(LIBFT_DIR)



all: $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME_CLIENT): $(LIBFT) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(INCLUDE) $(LDFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT) $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(INCLUDE) $(LDFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf *.o

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf server client

re : fclean all

.PHONY: all clean fclean re