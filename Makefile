NAME = endgame
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses -lpthread

all: 
	clang $(CFLAGS) *.c -o $(NAME) 

install: 
	cp ./src/*.c .
	cp ./inc/*.h .
	clang $(CFLAGS) *.c -o $(NAME)

uninstall: clean
	rm -rf $(NAME)

clean: uninstall
	rm -rf *.c
	rm -rf *.h

reinstall: uninstall install
