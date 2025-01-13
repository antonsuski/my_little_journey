PROG := prog

all: clean $(PROG)

$(PROG): main.o
	g++ main.o -o $(PROG) -I ./obs.hxx

main.o: obs.o
	g++ -c main.cxx -o main.o

obs.o:
	g++ -c obs.cxx -o obs.o

clean:
	rm -rf *.o $(PROG)

@phony: clean all

