NAME := phonebook
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := $(wildcard *.cpp)
OBJ := $(SRC:%.cpp=%.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(NAME)
	./$(NAME)

re: clean $(NAME)

clean:
	rm -f *.o $(NAME)

.PHONY: all run test clean