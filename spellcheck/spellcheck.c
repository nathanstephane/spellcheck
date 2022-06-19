#include <stdio.h>
#include <ctype.h>

#include"dictionary.c"


int main(int argc, char* argv[]) {

	char* filename = (argc == 2) ? argv[1] : "test.txt";
	printf("Filename: %s", filename );

	//load dictionary
	if (!load()) {
		printf("Could not load dictionary.Try again\n");
		return 1;
	}

	

	return 0;
}