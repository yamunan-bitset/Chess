CXX        = g++
LINKERLIBS = -lsfml-window -lsfml-audio -lsfml-system -lsfml-graphics
CXXFLAGS   = -std=c++17 -g -fno-stack-protector 
CPPFLAGS   = -I/usr/include/SFML/
OUT        = chess
OBJS       = src/turn.o src/notation.o src/board.o src/coordinate.o \
		src/position.o src/chess_piece.o src/main.o

build: $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(CPPFLAGS) $(LINKERLIBS) -o $(OUT)

clean:
	rm -rf $(OBJS) $(OUT)

