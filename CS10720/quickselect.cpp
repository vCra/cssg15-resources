#include <stdio.h> /* library needed to do the output */
#include <stdlib.h> /* library needed for EXIT_FAILURE, EXIT_SUCCESS */
#include <time.h> /* library needed for time() and clock() */
#include <assert.h>

#define NMAX 200000000 /* this defines the maximal array size */

long *keys, *copyOfKeys; /* the two arrays of keys */
long n; /* number of key in the array; cannot be more than NMAX */

int		checkArgs(int argc, char **argv); /* checks if arguments are okay, returns 1 if they are not */
void	useArgs(char **argv); /* store values of n and searches as given in command line arguments */

void initArray(long *keys, long n) {
	long i;

	keys[0] = rand(); /* select first key randomly */
	for (i = 1; i<n; i++)
		if ((rand() % 2)) /* check of next random integer is odd */
			keys[i] += rand(); /* increase */
		else
			keys[i] -= rand(); /* descrease */
}

long partition(long *keys, long left, long right, long pivot) {
	long swap; /* used for key swap */

	while (left < right) {
		while (keys[left] < keys[pivot])
			left++; /* search for wrongly placed item */
		while (keys[right] > keys[pivot])
			right--; /* search for wrongly placed item */
					 /* swap items */
		swap = keys[left];
		keys[left] = keys[right]; keys[right] = swap;
		/* check if pivot was swapped */
		if (left == pivot)
			pivot = right; /* update pivot position */
		else if (right == pivot)
			pivot = left; /* update pivot position */\
			if (left<pivot)
				left++; /* force index to move if different from pivot */
		if (right>pivot)
			right--; /* force index to move if different from pivot */
	}
	return pivot; /* return updated pivot position */
}

void quickSort(long *keys, long start, long size) {
	long pivot; /* index of pivot element */

	if (size < 2)
		return; /* nothing to do for arrays of size < 2 */
	pivot = start + (size / 2); /* select some pivot element */
	pivot = partition(keys, start, start + size - 1, pivot); /* partition input */
	if (pivot - start < size - pivot - 1) { /* check size of parts */
		quickSort(keys, start, pivot - start); /* sort smaller part */
		quickSort(keys, pivot + 1, start + size - pivot - 1); /* sort larger part */
	}
	else {
		quickSort(keys, pivot + 1, start + size - pivot - 1); /* sort smaller part */
		quickSort(keys, start, pivot - start); /* sort larger part */
	}
}

long quickSelect(long *keys, long start, long size, long r) {
	long pivot; 

	if (size < 2)
		return start; 
	pivot = start + rand()%size; 
	pivot = partition(keys, start, start + size - 1, pivot); 
	if (pivot + 1 == r) {
		return pivot + 1;
	}
	else if (pivot + 1 > r) {
		return quickSelect(keys, start, pivot - start, r);
	} else {
		return quickSelect(keys, pivot + 1, start + size - pivot - 1, r);
	}
}

int main(int argc, char **argv) {
	clock_t	runtime, start;	/* to keep track of running time */
	long	i; /* index variable for copying keys */
	long	median; /* median value */

					/* check arguments for problems and exit if a problem exists */
	if (checkArgs(argc, argv))
		return EXIT_FAILURE; /* exit because of problem with the arguments */

	useArgs(argv); /* set n according to command line arguments */

				   /* obtain space for the two arrays */
	keys = (long *)malloc(sizeof(long)*n * 2); /* twice as much as needed for keys */
	assert(keys != NULL);
	copyOfKeys = keys + n; /* set copyOfKeys to second half */

						   /* initialise random number generator */
	srand((unsigned int)time(NULL));
	initArray(keys, n); /* initialise array */
						/* make copy of array */
	for (i = 0; i<n; i++)
		copyOfKeys[i] = keys[i];
	/* use quickSelect to extract median */
	start = clock();
	median = keys[quickSelect(keys, 0, n, (n / 2) + 1)];
	runtime = clock() - start; /* take time for insertion sort */
	fprintf(stdout, "Quick select needs %.5f seconds to find "
		"the median %ld of %ld items.\n", (double)runtime / (double)CLOCKS_PER_SEC,
		median, n);
	/* use quickSort to extract median */
	start = clock();
	quickSort(copyOfKeys, 0, n);
	median = copyOfKeys[n / 2];
	runtime = clock() - start; /* take time for insertion sort */
	fprintf(stdout, "Quick sort needs %.5f seconds to find "
		"the median %ld of %ld items.\n", (double)runtime / (double)CLOCKS_PER_SEC,
		median, n);

	free(keys);
	return EXIT_SUCCESS; /* exit after normal operation */
}

int checkArgs(int argc, char **argv) {
	long	tmp;

	/* This function checks if the arguments are okay, i.e., if */
	/* (1) if the number of arguments is 1 */
	/* (2) if the size of the array is between 1 and NMAX */

	if (argc != 2) {
		fprintf(stderr, "%s: Expecting one parameter but received %d.\n",
			argv[0], argc - 1);
		fprintf(stderr, "Usage: %s n\nwhere n is size of array\n", argv[0]);
		return 1;
	}
	tmp = atol(argv[1]);
	if (tmp<1) {
		fprintf(stderr, "%s: Parameter n (size of array) needs to be at "
			"least 1, received %s (read as %ld).\n", argv[0], argv[1], tmp);
		return 1;
	}
	if (tmp>NMAX) {
		fprintf(stderr, "%s: Parameter n (size of array) needs to be at "
			"most %d, received %s (read as %ld).\n",
			argv[0], (int)NMAX, argv[1], tmp);
		return 1;
	}

	return 0; /* return 0 if all was okay */
}

void useArgs(char **argv) {
	n = atol(argv[1]);
}
