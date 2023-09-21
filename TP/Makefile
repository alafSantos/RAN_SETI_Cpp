EXE = sensorHandler

.PHONY: run clean

all:
	cd build && cmake .. && make && cd ..

run:
	./$(EXE)

clean:
	rm -rf $(EXE) build/*