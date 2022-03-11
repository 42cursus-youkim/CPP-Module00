NAME := megaphone
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := megaphone.cpp
OBJ := $(SRC:%.cpp=%.o)

.PHONY: all run test clean

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

run: $(NAME)
	./$(NAME)

clean:
	rm -f *.o
	rm -f $(NAME)
