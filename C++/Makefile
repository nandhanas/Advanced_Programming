CXX=c++
CXXFLAGS= -Wall -Wextra -std=c++11 -O3

SRC= main.cpp performance.cpp
EXE=$(SRC:.cpp=.o)

all: $(EXE)

%.o:%.cpp
	      $(CXX) $(CXXFLAGS) $< -o $@

docs:
			doxygen Doxyfile

clean:
				rm -rf *~ $(EXE)

.PHONY: clean all

format:
				clang-format -i $(SRC)

.PHONY: format
