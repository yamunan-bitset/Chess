CXX        = g++
LINKERLIBS = -lsfml-window -lsfml-system -lsfml-graphics
CXXFLAGS   = -std=c++17
CPPFLAGS   = -I/usr/include/SFML/
OUT        = chess
OBJS       = src/turn.o src/board.o src/chess.o src/main.o

build: $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(CPPFLAGS) $(LINKERLIBS) -o $(OUT)

clean:
	rm -rf $(OBJS) $(OUT)
	
