all: main.c
	gcc main.c

clean:
	rm a.out

run: all
	./a.out
