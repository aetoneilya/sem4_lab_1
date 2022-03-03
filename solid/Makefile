CC=g++
CPPFLAGS=-Iinclude/ 
MAIN = src/main.cpp
LIBSRC=$(filter-out $(MAIN), $(wildcard src/*.cpp))
LIBOBJ=$(LIBSRC:.cpp=.o)
EXECUTABLE=build/result_file


.PHONY: all build test clean rebuild

all: build

build: clean $(MAIN:.cpp=.o) $(LIBOBJ)
	$(CC) $(MAIN:.cpp=.o) $(LIBOBJ) -o $(EXECUTABLE) -pthread

test: build
	./$(EXECUTABLE) 

%.o: src/%.cpp
	$(CC) -c $(CPPFLAGS) $^ -o $@

style:
	cppcheck --enable=all --suppress=missingIncludeSystem src/

clean:
	rm -rf src/*.o $(EXECUTABLE)

rebuild: clean all

