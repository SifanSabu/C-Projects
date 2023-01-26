#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

	/*char *ptr;

	if(argc <= 1) {
		printf("ERROR\n");
		return 0;
	}

	long conv = strtol( argv[1], &ptr, 10); */

	int input;

	scanf("%d", &input);

	if( input % 3 == 0 && input % 5 == 0) {
                printf("CS1714\n");
        }
	else if( input % 3 == 0) {
		printf("CS\n");
	}
	else if( input % 5 == 0) {
		printf("1714\n");
	}
	else {printf("ERROR\n");}

	//printf("Hello %s! %s\n", argv[1], argv[2]);
	return 0;
}
