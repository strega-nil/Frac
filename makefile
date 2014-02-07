all: _frac _calc
	clang obj/frac.o obj/calc.o -o calc

_frac:
	clang -Wall -Werror -pedantic -ggdb3 -c -std=c99 src/frac.c -o obj/frac.o

_calc:
	clang -Wall -Werror -pedantic -ggdb3 -c -std=c99 src/calc.c -o obj/calc.o

test:
	clang -Wall -Werror -pedantic -std=c99 src/frac.c src/test.c -o test
	./test
	rm test
