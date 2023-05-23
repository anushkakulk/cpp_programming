IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = q1.o
_OBJ2 = q2.o
_OBJ3 = q3.o


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: q1 q2 q3

	

q1: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

q2: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

q3: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f q1
	rm -f q2
	rm -f q3
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 


	