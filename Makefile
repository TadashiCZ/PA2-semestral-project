.PHONY: all run compile doc clean check
.DEFAULT_GOAL := all

#variables
CXX?=g++
CXXFLAGS?=-std=c++14 -Wall -pedantic -Wno-long-long -O0 -ggdb
SOURCES?=$(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)
EXECUTABLE?=valentad
MEMCHECK?=valgrind
MEMFLAGS?=--leak-check=full

%.o: %.cpp,%.hpp
	@$(CXX) $(CXXFLAGS) -c -o $@ -c $<
	@$(CXX) $(CXXFLAGS) -MM -MT $*.o $*.cpp > $*.d


all: clean doc compile

run: compile
	./$(EXECUTABLE)

compile: $(SOURCES:.cpp=.o)
	@$(CXX) $(CXXFLAGS) $(SOURCES:.cpp=.o) -o $(EXECUTABLE)

doc:
	@doxygen Doxyfile

clean:
	@rm -f -- $(wildcard src/*.o src/*/*.o src/*/*/*.o) $(wildcard src/*.d src/*/*.d src/*/*/*.d)
	@rm -f $(EXECUTABLE)
	@rm -rf doc/

check: CXXFLAGS =-std=c++14 -Wall -pedantic -Wno-long-long -g
check: clean compile
	$(MEMCHECK) ./$(EXECUTABLE) $(MEMFLAGS)



-include $(SOURCES:.cpp=.d)