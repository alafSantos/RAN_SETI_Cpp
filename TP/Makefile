CC = g++
LD = ld

EXE = sensorHandler

SRC = src/
LDIR = lib/
IDIR = includes/

DEPS = $(wildcard $(IDIR)*.h)
CPPFILES = $(wildcard $(LDIR)*.cpp) $(wildcard $(SRC)*.cpp)
OBJS = $(CPPFILES:.cpp=.o)
CFLAGS = -Wall -I includes/
LDLIBS = -lstdc++ -lm

.PHONY: all clean

all: $(EXE)

$(EXE):$(OBJS)
	 $(CC) $(CFLAGS) $^ -o $@ 
	 
run:
	./$(EXE)
	
clean:
	rm -f $(OBJS) $(EXE)