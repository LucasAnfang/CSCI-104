GXX = g++
CPPFLAGS = -g -Wall


BINDIR = bin

search: directory bin/mdparser.o bin/webpage.o bin/util.o bin/crawlerpages.o bin/crawler.o search.cpp
	${GXX} ${CPPFLAGS} bin/mdparser.o bin/webpage.o bin/util.o bin/crawlerpages.o bin/crawler.o search.cpp -o bin/search

bin/mdparser.o: mdparser.cpp mdparser.h
	${GXX} ${CPPFLAGS} -c -o bin/mdparser.o mdparser.cpp

bin/webpage.o: webpage.cpp webpage.h
	${GXX} ${CPPFLAGS} -c -o bin/webpage.o webpage.cpp

bin/util.o: util.cpp util.h
	${GXX} ${CPPFLAGS} -c -o bin/util.o util.cpp

bin/crawlerpages.o: crawlerpages.cpp crawlerpages.h
	${GXX} ${CPPFLAGS} -c -o bin/crawlerpages.o crawlerpages.cpp

bin/crawler.o: crawler.cpp crawler.h
	${GXX} ${CPPFLAGS} -c -o bin/crawler.o crawler.cpp

directory: ${BINDIR}

${BINDIR}:
	mkdir -p $@ 
	touch $@/.dirstamp

.PHONY: clean

clean:
	rm -rf bin
