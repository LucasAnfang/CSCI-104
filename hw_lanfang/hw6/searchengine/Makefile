#############################################################################
# Makefile for building: searchengine
# Generated by qmake (2.01a) (Qt 4.8.6) on: Mon Nov 9 18:35:12 2015
# Project:  searchengine.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile searchengine.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = FilenameComp.cpp \
		form.cpp \
		IncomingLinkComp.cpp \
		mdparser.cpp \
		OutgoingLinkComp.cpp \
		PageRankComp.cpp \
		search.cpp \
		searcheng.cpp \
		util.cpp \
		webpage.cpp moc_form.cpp
OBJECTS       = FilenameComp.o \
		form.o \
		IncomingLinkComp.o \
		mdparser.o \
		OutgoingLinkComp.o \
		PageRankComp.o \
		search.o \
		searcheng.o \
		util.o \
		webpage.o \
		moc_form.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		searchengine.pro
QMAKE_TARGET  = searchengine
DESTDIR       = 
TARGET        = searchengine

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: searchengine.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile searchengine.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile searchengine.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/searchengine1.0.0 || $(MKDIR) .tmp/searchengine1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/searchengine1.0.0/ && $(COPY_FILE) --parents FilenameComp.h form.h IncomingLinkComp.h mdparser.h msort.h myset.h OutgoingLinkComp.h pageparser.h PageRankComp.h searcheng.h util.h webpage.h .tmp/searchengine1.0.0/ && $(COPY_FILE) --parents FilenameComp.cpp form.cpp IncomingLinkComp.cpp mdparser.cpp OutgoingLinkComp.cpp PageRankComp.cpp search.cpp searcheng.cpp util.cpp webpage.cpp .tmp/searchengine1.0.0/ && (cd `dirname .tmp/searchengine1.0.0` && $(TAR) searchengine1.0.0.tar searchengine1.0.0 && $(COMPRESS) searchengine1.0.0.tar) && $(MOVE) `dirname .tmp/searchengine1.0.0`/searchengine1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/searchengine1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_form.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_form.cpp
moc_form.cpp: myset.h \
		webpage.h \
		searcheng.h \
		pageparser.h \
		util.h \
		mdparser.h \
		form.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) form.h -o moc_form.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

FilenameComp.o: FilenameComp.cpp FilenameComp.h \
		webpage.h \
		myset.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FilenameComp.o FilenameComp.cpp

form.o: form.cpp form.h \
		myset.h \
		webpage.h \
		searcheng.h \
		pageparser.h \
		util.h \
		mdparser.h \
		FilenameComp.h \
		msort.h \
		IncomingLinkComp.h \
		OutgoingLinkComp.h \
		PageRankComp.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o form.o form.cpp

IncomingLinkComp.o: IncomingLinkComp.cpp IncomingLinkComp.h \
		webpage.h \
		myset.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o IncomingLinkComp.o IncomingLinkComp.cpp

mdparser.o: mdparser.cpp mdparser.h \
		pageparser.h \
		myset.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mdparser.o mdparser.cpp

OutgoingLinkComp.o: OutgoingLinkComp.cpp OutgoingLinkComp.h \
		webpage.h \
		myset.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o OutgoingLinkComp.o OutgoingLinkComp.cpp

PageRankComp.o: PageRankComp.cpp PageRankComp.h \
		webpage.h \
		myset.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PageRankComp.o PageRankComp.cpp

search.o: search.cpp webpage.h \
		myset.h \
		searcheng.h \
		pageparser.h \
		util.h \
		mdparser.h \
		form.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o search.o search.cpp

searcheng.o: searcheng.cpp searcheng.h \
		webpage.h \
		myset.h \
		pageparser.h \
		util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o searcheng.o searcheng.cpp

util.o: util.cpp util.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o util.o util.cpp

webpage.o: webpage.cpp webpage.h \
		myset.h \
		mdparser.h \
		pageparser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o webpage.o webpage.cpp

moc_form.o: moc_form.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_form.o moc_form.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

