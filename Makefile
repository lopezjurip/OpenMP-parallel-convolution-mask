compile: lib/imagelib/imagelib.c src/main.c
	mkdir -p build
	gcc-7 -lpng -o build/secuential lib/imagelib/imagelib.c src/main.c -I.
	gcc-7 -lpng -fopenmp -o build/parallel lib/imagelib/imagelib.c src/main.c -I.
