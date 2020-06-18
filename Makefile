SOURCEFILES = interface.c commands.c

all: clean
	gcc -o endlesstower $(SOURCEFILES) -lreadline

run: all
	./endlesstower


clean:
	rm -f endlesstower
