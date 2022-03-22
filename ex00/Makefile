NAME := megaphone
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := megaphone.cpp
OBJ := $(SRC:%.cpp=%.o)

.PHONY: all run test clean

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(NAME)
	./$(NAME)

clean:
	rm -f *.o
	rm -f $(NAME)
