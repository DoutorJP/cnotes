all: cnotes

cnotes: main.c
	gcc -o cnotes main.c 
	mv cnotes build/
clean: main.c
	rm build/*
	gcc -o cnotes main.c
	mv cnotes build/

