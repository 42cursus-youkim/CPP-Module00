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

test: $(NAME)
	python3 test.py

clean:
	rm -f *.o
	rm -f $(NAME)

.PHONY: all run test clean