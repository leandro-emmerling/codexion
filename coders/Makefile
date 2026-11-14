NAME =		codexion

SRC_DIR = 	./
SRC = 		main.c \
			parsing.c \
			utils.c \
			time_utils.c

HD = $(SRC_DIR)codexion.h

OBJ_DIR =	obj/
OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC =		cc

CFLAGS =	-Wall -Wextra -Werror -pthread

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HD) | $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				rm -rf $(OBJ_DIR)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re