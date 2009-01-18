#include <stdio.h>

#include "mjtrb.h"

#define COUNT 4

int main(int argc, char *argv[]) {
	struct mjtrb *rb, *rbptr;

	int i = 0;

	rbptr = rballoc(COUNT);
	if (rbptr == NULL) {
		printf("Died");
		return 1;
	}

	rb = rbptr;
	do {
		printf("%2d: Dealing with ptr at 0x%x", i, rb);
		printf(" next -> 0x%x\n", rb->next);
		rb = rb->next;
		i++;
	} while (rb != rbptr && i < COUNT+666);

	printf("Came around to: 0x%x\n", rb);

	return 0;
}

