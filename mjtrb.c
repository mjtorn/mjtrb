#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "mjtrb.h"

struct mjtrb *rballoc(int count) {
	int i;

	struct mjtrb *first_ptr = NULL;
	struct mjtrb *rb_ptr;

	// We need at least two
	if (count < 2) {
		return NULL;
	}

	// -1 o_O
	for (i=0; i<count-1; i++) {
		if (!first_ptr) {
			first_ptr = rb_ptr = (struct mjtrb *) malloc(sizeof(struct mjtrb));
			assert(rb_ptr != NULL);
			first_ptr->idx = rb_ptr->idx = i;
			printf("%2d: Allocing with %d ptr at 0x%x\n", i, rb_ptr->idx, rb_ptr);
			rb_ptr->next = (struct mjtrb *) malloc(sizeof(struct mjtrb));
			rb_ptr = rb_ptr->next;
			continue;
		}
		rb_ptr->idx = i;
		printf("%2d: Allocing with %d ptr at 0x%x\n", i, rb_ptr->idx, rb_ptr);
		// Where the hell did this hack come from?
		if (i < count-2) {
			rb_ptr->next = (struct mjtrb *) malloc(sizeof(struct mjtrb));
			rb_ptr = rb_ptr->next;
		}
	}
	assert(rb_ptr->next == NULL);
	rb_ptr->next = first_ptr;

	return first_ptr;
}

void rbfree(struct mjtrb *first) {
	struct mjtrb *rb, *prev = NULL;

	rb = first;
	do {
		prev = rb;
		rb = rb->next;
		free(prev);
	} while (rb != first);
	assert(((rb == first) == prev) == NULL);

}

