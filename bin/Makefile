SRC:= ../src/*.cpp
OBJ:= main.o Participant.o Categorie.o Combat.o

all: judo

judo: ${SRC} 

	@g++ -g -c ${SRC}
	@g++ -g -o judo ${OBJ}

clean:
	@-rm -rf *.o judo