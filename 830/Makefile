CXX=g++
CXXFLAGS=-Wall -Wshadow -std=c++17 -O3

all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

%.out: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
	cp $@ $(@:.out=)

clean:
	rm -f *.out


