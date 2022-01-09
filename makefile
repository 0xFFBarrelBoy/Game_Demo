CC = clang++
CFLAGS = -Wall -g -std=c++17 -stdlib=libc++ -I/opt/homebrew/include -L/opt/homebrew/lib  -lSDL2 -lSDL2_image
SRC = src
BUILDDIR = build/

all:
	$(CC) $(CFLAGS) $(SRC)/main.cpp  $(SRC)/GameWindow.cpp $(SRC)/Game.cpp $(SRC)/Input.cpp \
	$(SRC)/Sprite.cpp -o 0xFFBB.out

dir:
	mkdir -p $(BUILDDIR)

clean: 
	rm -rf $(BUILDDIR)