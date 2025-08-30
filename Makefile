CXX=g++
CXXFLAGS=-Wall -Werror -std=c++11 -O3

all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

%.out: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $(@:.out=)

clean: $(patsubst %.cpp, %.clean, $(wildcard *.cpp))

%.clean:
	rm -f $(@:.clean=)
