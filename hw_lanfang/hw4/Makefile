GXX = g++
CPPFLAGS = -g -Wall


BINDIR = bin

all: mysettest mdparsertest webpagetest

mysettest: directory bin/myset.o myset.cpp
	${GXX} ${CPPFLAGS}  bin/myset.o mysettest.cpp -o bin/mysettest

mdparsertest: directory bin/myset.o bin/mdparser.o mdparsertest.cpp
	${GXX} ${CPPFLAGS}  bin/myset.o bin/mdparser.o mdparsertest.cpp -o bin/mdparsertest

webpagetest: directory bin/myset.o bin/mdparser.o bin/webpage.o webpagetest.cpp
	${GXX} ${CPPFLAGS}  bin/myset.o bin/mdparser.o bin/webpage.o webpagetest.cpp -o bin/webpagetest

search: directory bin/myset.o bin/mdparser.o bin/webpage.o bin/util.o bin/searcheng.o search.cpp
	${GXX} ${CPPFLAGS}  bin/myset.o bin/mdparser.o bin/webpage.o bin/util.o bin/searcheng.o search.cpp -o bin/search

bin/myset.o: myset.cpp myset.h
	${GXX} ${CPPFLAGS} -c -o bin/myset.o myset.cpp

bin/mdparser.o: mdparser.cpp mdparser.h
	${GXX} ${CPPFLAGS} -c -o bin/mdparser.o mdparser.cpp

bin/webpage.o: webpage.cpp webpage.h
	${GXX} ${CPPFLAGS} -c -o bin/webpage.o webpage.cpp

bin/util.o: util.cpp util.h
	${GXX} ${CPPFLAGS} -c -o bin/util.o util.cpp

bin/searcheng.o: searcheng.cpp searcheng.h
	${GXX} ${CPPFLAGS} -c -o bin/searcheng.o searcheng.cpp

directory: ${BINDIR}

${BINDIR}:
	mkdir -p $@ 
	touch $@/.dirstamp

.PHONY: tests

tests: mysettest mdparsertest webpagetest
	-@$(BINDIR)/mysettest
	-@echo "--- All Tested!---"

	-@$(BINDIR)/mdparsertest
	-@echo "--- All Tested!---"	

	-@$(BINDIR)/webpagetest
	-@echo "--- All Tested!---"	

.PHONY: clean

clean:
	rm -rf bin
