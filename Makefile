# gmake
CXX = g++
CXXFLAGS = -g -Wall -O2
SRCMODULES = finegrainedqueue.cpp
OBJMODULES = $(SRCMODULES:.c=.o)

%.o: %.c %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

out: main.cpp $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^ -o $@
run: out
	./out

clean:
	rm -rf *.o out

.PHONY: all run clena
