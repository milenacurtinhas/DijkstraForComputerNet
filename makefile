CC = gcc
CFLAGS = -I./include -Wall -g
LIBS := -lm
OBJDIR = objects
SRCDIR = src

OBJECTS = $(OBJDIR)/dijkstra.o $(OBJDIR)/edge.o $(OBJDIR)/PQ.o $(OBJDIR)/vertex.o $(OBJDIR)/RTT.o
ALL_OBJECTS = $(shell find . -type f -name "*.o" -print) 

all: trab2

$(OBJDIR):
	mkdir -p $(OBJDIR)
	
trab2: $(OBJDIR) $(OBJECTS) client.c
	$(CC) $(CFLAGS) -o trab1 client.c $(OBJECTS) $(LIBS)

$(OBJDIR)/dijkstra.o: $(SRCDIR)/dijkstra.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/dijkstra.c -o $(OBJDIR)/dijkstra.o

$(OBJDIR)/edge.o: $(SRCDIR)/edge.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/edge.c -o $(OBJDIR)/edge.o

$(OBJDIR)/PQ.o: $(SRCDIR)/PQ.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/PQ.c -o $(OBJDIR)/PQ.o

$(OBJDIR)/vertex.o: $(SRCDIR)/vertex.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/vertex.c -o $(OBJDIR)/vertex.o

$(OBJDIR)/RTT.o: $(SRCDIR)/RTT.c
	$(CC) $(CFLAGS) -c $(SRCDIR)/RTT.c -o $(OBJDIR)/RTT.o


clean:

	rm -f trab2 $(OBJDIR)/*.o 
	rm -rf $(OBJDIR)
	rm -f *.bin
	rm -f *.txt