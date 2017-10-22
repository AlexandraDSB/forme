# Makefile pour EZ-Draw++ : version pour UNIX
#
# 01/02/2017 - Eric.Remy@univ-amu.fr

# Variables pour Unix/X11
SHELL=/bin/bash

ifeq ($(CXX),)
CXX=g++
endif
CFLAGS   = -g -Wall -W -pedantic -O2
CXXFLAGS = $(CFLAGS) -std=c++11
LDFLAGS  =
LIBS     = -L/usr/X11R6/lib -lX11 -lXext
RM       = rm -rf

.PHONY: all help eedit clean distclean doc docclean olddoc olddocclean

# Rajoutez vos executables C++ a la fin de EXECSPP =
#
EXECSPP = main.exe \
  

all :: $(EXECSPP)

.cpp.o :
	$(CXX) -c $(CXXFLAGS) $*.cpp


# Cette double dependance un peu speciale est une syntaxe spécifique à GNU-make ;
# elle est équivalente à :
#     demo++01 : demo++01.o ez-draw++.o
#     demo++02 : demo++02.o ez-draw++.o
#     etc.
$(EXECSPP)    : % : %.o ez-draw++.o MyWindow.o formes.o forme.o point.o rectangle.o ellipse.o carre.o cercle.o triangle.o
	$(CXX) -o $@ $^ $(LIBS) $(LDFLAGS)

ez-draw++.o : ez-draw++.hpp ez-draw++.cpp

MyWindow.o :MyWindow.hpp MyWindow.cpp 

formes.o : formes.hpp formes.cpp

forme.o : forme.hpp forme.cpp

point.o : point.hpp point.cpp

rectangle.o : rectangle.hpp rectangle.cpp

ellipse.o : ellipse.hpp ellipse.cpp

carre.o : carre.hpp carre.cpp

cercle.o: cercle.hpp cercle.cpp

triangle.o: triangle.hpp triangle.cpp



clean ::
	$(RM) *.o core

distclean :: clean
	$(RM) *% *~ .*.swp $(EXECSPP)

