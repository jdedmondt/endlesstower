SOURCEFILES = interface.c commands.c game.c debug.c

all: clean
	gcc -o endlesstower $(SOURCEFILES) -lreadline

run: all
	./endlesstower


clean:
	rm -f endlesstower
