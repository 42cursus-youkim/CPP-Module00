NAME := phonebook
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := $(wildcard *.cpp)
OBJ := $(SRC:%.cpp=%.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

run: $(NAME)
	./$(NAME)

re: clean $(NAME)

clean:
	rm -f *.o $(NAME)

.PHONY: all run test clean