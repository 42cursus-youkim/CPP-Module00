NAME := megaphone
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := megaphone.cpp
OBJ := $(SRC:%.cpp=%.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $<

run: $(NAME)
	python3 test.py

clean:
	rm -f *.o
	rm -f $(NAME)

.PHONY: all clean