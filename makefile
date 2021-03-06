all : basics calculator palindrome hex2int convert_getopt memdmp memcopy random_fill inputsort inputsort_malloc recursion_reverse linked_list_test

basics : basics.c
	gcc -o basics basics.c

calculator: calculator.c
	gcc -o calculator calculator.c
	
palindrome: palindrome.c
	gcc -o palindrome palindrome.c	
	
hex2int: hex2int.c
	gcc -o hex2int hex2int.c
	
convert_getopt : convert_getopt.c
	gcc -o convert_getopt convert_getopt.c

memdmp : memdmp.c libmemdmp.c
	gcc -o memdmp memdmp.c libmemdmp.c

memcopy : memcopy.c libmemdmp.c
	gcc -g -o memcopy memcopy.c libmemdmp.c

random_fill : random_fill.c 
	gcc -g -o random_fill random_fill.c

inputsort : inputsort.c
	gcc -g -o inputsort inputsort.c	
	
inputsort_malloc : inputsort_malloc.c
	$(CC) -g -o inputsort_malloc inputsort_malloc.c	

recursion_reverse : recursion_reverse.c
	$(CC) -g -o recursion_reverse recursion_reverse.c
	
linked_list_test : linked_list_test.c linked_list.c linked_list.h
	$(CC) -Wall -Wextra -g -o linked_list_test linked_list_test.c linked_list.c -lcunit -fprofile-arcs -ftest-coverage
	
clean:
	rm  inputsort_malloc recursion_reverse linked_list_test
	
