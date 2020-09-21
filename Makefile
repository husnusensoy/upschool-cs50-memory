program?=bin/aliasing
opts?=

all: bin/main bin/multiplication bin/stack bin/heap bin/swapfail bin/swap bin/functional bin/betterstring bin/defaultstring bin/aliasing

bin/%: src/%.c
	gcc -Wall  $(opts) $< -o $@ -lm

docker: Dockerfile
	docker build -t c-development -f Dockerfile .

valgrind: 
	valgrind --tool=memcheck --leak-check=yes $(program)

clean:
	rm bin/*