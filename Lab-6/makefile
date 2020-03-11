compileAll	:	main.o	mergesort_iterative.o	mergesort_recursive.o
	gcc main.o mergesort_iterative.o mergesort_recursive.o -o output
main.o	:	main.c	helper.h
	gcc -c main.c
mergesort_iterative.o	:	mergesort_iterative.c	helper.h
	gcc -c mergesort_iterative.c
mergesort_recursive.o	:	mergesort_recursive.c	helper.h
	gcc -c mergesort_recursive.c	