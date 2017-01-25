GXX = g++
CPPFLAGS = -g 

BINDIR = bin

all: hashtest minheaptest 

#hashtest: directory bin/hashtable.o hashtest.cpp
#	${GXX} ${CPPFLAGS}  bin/hashtable.o hashtest.cpp -o bin/hashtest

#minheaptest: directory bin/hashtable.o bin/minheap.o minheaptest.cpp
#	${GXX} ${CPPFLAGS}  bin/hashtable.o bin/minheap.o minheaptest.cpp -o bin/minheaptest

doublet: directory bin/hashtable.o bin/minheap.o doublet.cpp
	${GXX} ${CPPFLAGS}  bin/hashtable.o bin/minheap.o doublet.cpp -o bin/doublet	

bin/hashtable.o: hashtable.cpp hashtable.h
	${GXX} ${CPPFLAGS} -c -o bin/hashtable.o hashtable.cpp

bin/minheap.o: minheap.cpp minheap.h
	${GXX} ${CPPFLAGS} -c -o bin/minheap.o minheap.cpp

directory: ${BINDIR}

${BINDIR}:
	mkdir -p $@ 
	touch $@/.dirstamp	

.PHONY: clean

clean:
	rm -rf bin