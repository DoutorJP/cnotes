all: cnotes

cnotes: main.c
	gcc -o cnotes main.c 
clean: main.c
	rm cnotes
	gcc -o cnotes main.c
