IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = q1file1.o
_OBJ2 = q1file2.o
_OBJ3 = q1file3.o
_OBJ4 = q2.o
_OBJ5 = q3.o
_OBJ6 = q4.o

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: q1file1 q1file2 q1file3 q2 q3 q4

	
q1file1: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

q1file2: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

q1file3: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

q2: $(_OBJ4)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

q3: $(_OBJ5)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

q4: $(_OBJ6)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f q1file1
	rm -f q1file2
	rm -f q1file3
	rm -f q2
	rm -f q3
	rm -f q4
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 


	