GXX = g++
CPPFLAGS = -g -Wall


BINDIR = bin

graphcoloring: graphcoloring.o
	${GXX} ${CPPFLAGS} graphcoloring.o -o graphcoloring

graphcoloring.o: graphcoloring.cpp
	${GXX} ${CPPFLAGS} -c graphcoloring.cpp

clean:
	\rm *.o *~ graphcoloring
