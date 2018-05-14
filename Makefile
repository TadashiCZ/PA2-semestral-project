
.DEFAULT_GOAL := all

CXX=g++
CXXFLAGS=-std=c++14 -Wall -pedantic -Wno-long-long -O0 -ggdb
LDFLAGS=-lncurses
SOURCES=$(wildcard src/*.cpp )
EXECUTABLE=valentad
MEMCHECK=valgrind
MEMFLAGS=--leak-check=full


%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ -c $< $(LDFLAGS)
	@$(CXX) $(CXXFLAGS) -MM -MT $*.o $*.cpp $(LDFLAGS) > $*.d

all: compile

run: compile
	./$(EXECUTABLE)

compile: $(SOURCES:.cpp=.o)
	@$(CXX) $(CXXFLAGS) $(SOURCES:.cpp=.o) -o $(EXECUTABLE) $(LDFLAGS)

doc:
	doxygen Doxyfile

clean:
	@rm -f -- src/*.o src/*/*.o src/*/*/*.o
	@rm -f -- src/*.d src/*/*.d src/*/*/*.d
	@rm -f $(EXECUTABLE)
	@rm -rf doc/

check: CXXFLAGS =-std=c++14 -Wall -pedantic -Wno-long-long -g -O2
check: clean compile
	$(MEMCHECK) ./$(EXECUTABLE) $(MEMFLAGS)	 	


-include $(SOURCES:.cpp=.d)