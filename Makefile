.DEFAULT_GOAL := all

#promene pro kompilator
CXX=g++
CXXFLAGS=-std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb
SOURCES=$(wildcard src/*.cpp )
EXECUTABLE=valentad
MEMCHECK=valgrind
MEMFLAGS=--leak-check=full

# $< značí první parametr závislosti (v našem případě vždy .cpp soubor)
# $@ značí cíl pravidla (tedy část před dvojtečkou)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ -c $<


all: clean compile

run: compile
	./$(EXECUTABLE)

compile: $(SOURCES:.cpp=.o)
	@$(CXX) $(CXXFLAGS) $(SOURCES:.cpp=.o) -o $(EXECUTABLE)

doc:
	doxygen Doxyfile

clean:
	@rm -f -- $(wildcard src/*.o) $(wildcard src/*.d)
	@rm -f $(EXECUTABLE)
	@rm -rf doc/

check: CXXFLAGS =-std=c++14 -Wall -pedantic -Wno-long-long -g -O2
check: clean compile
	$(MEMCHECK) ./$(EXECUTABLE) $(MEMFLAGS)	 	
