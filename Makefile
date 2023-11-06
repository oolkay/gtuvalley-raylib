NAME = csgo
CC = c++
CFLAGS = -Wall -Wextra -Werror
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
LINKS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(OBJ) -o $(NAME) $(LINKS)

%.o: %.cpp
	$(CC)  -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re