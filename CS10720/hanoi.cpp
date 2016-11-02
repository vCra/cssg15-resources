#include <stdio.h>
#include <stdlib.h>

void hanoi(int disks, char start, char tmp, char goal) {
	if (disks == 1) {
		fprintf(stdout, "move top disk from %c to %c\n", start, goal);
	}
	else {
		hanoi(disks - 1, start, goal, tmp);
		fprintf(stdout, "move top disk from %c to %c\n", start, goal);
		hanoi(disks - 1, tmp, start, goal);
	}
}

int main(int argc, char **argv) {
	int	n;

	if (argc != 2) {
		fprintf(stderr, "Error: %s expects 1 argument but received %d.\n",
			argv[0], argc - 1);
		fprintf(stderr, "Usage: %s n\nwhere n gives the number of disks\n",
			argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((n = atoi(argv[1])) < 1) {
		fprintf(stderr, "Error: %s expects number of disks to be at least 1. Received %s (read as %d).\n",
			argv[0], argv[1], n);
		exit(EXIT_FAILURE);
	}

	hanoi(n, 'L', 'M', 'R');

	return EXIT_SUCCESS;
}
