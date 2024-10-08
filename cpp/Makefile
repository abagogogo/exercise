CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

#LATEST_CC := $(shell find . -type f -name "*.cc" | xargs stat --format '%Y:%n' | sort -nr | awk -F: '{print $$2}' | head -n1)
LATEST_CC := $(shell ls -t *.cc 2>/dev/null | head -n1)
SOURCE ?= $(LATEST_CC)

EXE = ./a.out

default: clean $(EXE) run

$(EXE): $(SOURCE)
	@echo "---- Compiling $< ----"	
	$(CXX) $(CXXFLAGS) -o $@ $<
	@echo "---- Output: $@ ----"	

run: $(EXE)
	@echo "---- running $(EXE) ----"	
	./$(EXE)

edit:
	vim $(SOURCE_CPP)

clean:
	rm -f $(OBJECTS) $(EXE)
	rm -f *~
	rm -f .*.un~
	rm -f .*.swp~
