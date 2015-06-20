CC = clang++

CXXFLAGS = -Wall -Wextra -Werror -Iincludes

LDFLAGS =

NAME = ft_retro

SRCS =	src/Main.cpp\
		src/Background.Class.cpp \
		src/Enemy.Class.cpp\
		src/Entity.Class.cpp\
		src/GameCore.Class.cpp\
		src/Menu.Class.cpp\
		src/Player.Class.cpp\
		src/Projectile.Class.cpp\
		src/Screnn.Class.cpp\
		src/Ship.Class.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CXXFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

