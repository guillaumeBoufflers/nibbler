NAME=	nibbler

CXX=	g++ -g -Wall -Wextra -W -ldl

CC=	$(CXX)

OBJ=	src/main.o\
	src/Snake.o\
	src/Food.o\
	src/Collision.o\
	src/Game.o\
	src/Strategie.o\
	src/StratFact.o\
	src/GameException.o\
	src/Hole.o

all:	$(NAME)

$(NAME): $(OBJ)
	 $(CXX) $^ -o $@

	g++ -shared -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -o lib_nibbler_sfml.so ./sfml/src/Display.cpp -fPIC
	g++ -shared -lGL -lGLU -lSDL -o lib_nibbler_opengl.so opengl/src/Display.cpp  -fPIC
	g++ -shared -lncurses -o lib_nibbler_ncurses.so ./ncurses/src/Display.cpp -fPIC

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	rm -f lib_nibbler_sfml.so
	rm -f lib_nibbler_ncurses.so
	rm -f lib_nibbler_opengl.so

re:	fclean all