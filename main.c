#include "monty.h"

/**
 * main - entry point
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *fi;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fi = fopen(argv[1], "r");
	if (!fi)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	process_file(fi);

	fclose(fi);
	return (0);
}
