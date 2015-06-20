CC = clang++

CXXFLAGS = -Wall -Wextra -Werror -Iincludes

NCURSES = -lncurses

NAME = ft_retro

SRCS =	src/Main2.cpp\
		src/Background.Class.cpp \
		src/Enemy.Class.cpp\
		src/Entity.Class.cpp\
		src/GameCore.Class.cpp\
		src/Menu.Class.cpp\
		src/Player.Class.cpp\
		src/Projectile.Class.cpp\
		src/Screen.Class.cpp\
		src/Ship.Class.cpp\
		src/FTime.Class.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $^ $(NCURSES)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CXXFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

