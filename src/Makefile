CCFLAGS=-I. -O2
LDFLAGS=-lglut -lGLU -lGL -lXmu -lXext -lXi -lX11 -lm -O2

OBJECTS=test.o image.o world.o testbullet.o player.o testplayer.o

all: $(OBJECTS)
	g++ $(LDFLAGS) $(OBJECTS)

%.o: %.cc
	g++ $(CCFLAGS) $< -c

clean:
	rm -f $(OBJECTS)
	rm -f a.out
