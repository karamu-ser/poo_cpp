SRCS = projet.cpp
OBJ = $(SRCS:.cpp=.o)
NAME = projet
CC = g++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

$(OBJ): %.o : %.cpp projet.h
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all

run:	$(NAME)
	./$(NAME)