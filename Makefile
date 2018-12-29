CPPFLAGS = -Wall -Wpedantic -std=c++11

.PHONY: all clean re

all: main

main:
	g++ ${CPPFLAGS} -o main main.cpp wine_private.cpp wine.cpp

clean:
	/bin/rm -f main

re: clean all
