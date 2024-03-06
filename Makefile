CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

NAME_CLIENT = client
NAME_CLIENT_BONUS = client_bonus

NAME_SERVER = server
NAME_SERVER_BONUS = server_bonus

SRC_SERVER = server.c
OBJ_SERVER = server.o

SRC_SERVER_BONUS = server_bonus.c
OBJ_SERVER_BONUS = server_bonus.o

SRC_CLIENT = client.c
OBJ_CLIENT = client.o

SRC_CLIENT_BONUS = client_bonus.c
OBJ_CLIENT_BONUS = client_bonus.o

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a
LDFLAGS = -L $(LIBFT_DIR) -lft

INCLUDE = -I $(LIBFT_DIR)



all: $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus : $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(LIBFT) $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) -o $(NAME_CLIENT_BONUS) $(INCLUDE) $(LDFLAGS)

$(NAME_SERVER_BONUS): $(LIBFT) $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) -o $(NAME_SERVER_BONUS) $(INCLUDE) $(LDFLAGS)

$(NAME_CLIENT): $(LIBFT) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT) $(INCLUDE) $(LDFLAGS)

$(NAME_SERVER): $(LIBFT) $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER) $(INCLUDE) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf *.o

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf server client
	rm -rf server_bonus client_bonus

re : fclean all

.PHONY: all clean fclean re