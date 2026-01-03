NAME = base
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
FILES = main.cpp\
		A.cpp\
		B.cpp\
		C.cpp\
		Base.cpp
HFILES =A.hpp\
		B.hpp\
		C.hpp\
		Base.hpp

OBJ = $(FILES:.cpp=.o)

all : $(OBJ) $(NAME)
	

$(NAME): $(OBJ) $(HFILES)
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME)


%.o : %.cpp
	$(CC) $(CFLAGS) -c -O  $< -o $@
	
clean :
	rm -f $(OBJ) $(BOBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all re fclean clean
