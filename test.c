#include <stdio.h>

#include "mjtrb.h"

#define COUNT 6

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
		printf("%2d: Dealing with %d ptr at 0x%x", i, rb->idx, rb);
		printf(" next -> 0x%x\n", rb->next);
		rb = rb->next;
		i++;
	} while (rb != rbptr && i < COUNT+666);

	printf("Came around to: 0x%x\n", rb);

	rbfree(rbptr);

	return 0;
}

