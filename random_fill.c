#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_array(const int* array, const int size);


int main(int argc, char *argv[])
{
	const int size = 20;
	int random_array[size];
	time_t t;
	srand((unsigned) time(&t));

	//Generate the array
	for(int i=0; i<size; i++)
	{
		random_array[i] = rand() % 20;
	}

	printf("Original array:\n");
	print_array(random_array, size);


	//Allocate memory to store the unique numbers. This array will be used to track down duplicates.
	//Start by allocating room for 10 ints, then use realloc to double the size of the array each time it is full
	int unique_number_counter = 0;
	int max_uniques = 10;
	int * unique_numbers = malloc(sizeof(int)*max_uniques);
	if (unique_numbers == NULL)
	{
		exit(EXIT_FAILURE);
	}

	int current_number;

	for(int i=0; i<size; i++)
	{
		current_number = random_array[i];

		//Check whether the current number of the original array is already in the unique number array. If it is, then the current number is a duplicate
		char found = 0;
		for(int j=0; j<unique_number_counter; j++)
		{
			if (unique_numbers[j]==current_number)
			{
				found = 1; //Found, number not unique
				break; //Stop searching
			}
		}

		if (found == 0) //Not found : it is a unique number
		{
			if (unique_number_counter == max_uniques) //Unique number array is full, realloc required
			{
				max_uniques *= 2;
				unique_numbers = realloc(unique_numbers, sizeof(int)*max_uniques);
			}

			//Print a message printing the location at which the unique number is first encountered.
			printf("Number %2d first found at position %d.\n",current_number, i);
			unique_numbers[unique_number_counter] = current_number;

			unique_number_counter++;

		}
		else //It is a duplicate : print a message
		{
			printf("Number %2d again found at position %d.\n",current_number, i);


		}

	}

	//Print the unique number array
	printf("\n");
    printf("Array with duplicates removed:\n");
	print_array(unique_numbers, unique_number_counter);


	free(unique_numbers);

}

/*
 * void print_array(const int* array, const int size)
 *
 *
 * Print the array of size size pointed to by array
 *
 */


void print_array(const int* array, const int size)
{
	int col = 0;
	for(int i=0; i<size; i++)
	{
		col++;
		printf("%4d ", array[i]);

		if (col == 20)
		{

			printf("\n");
			col = 0;
		}
	}
	printf("\n");
}

