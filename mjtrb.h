struct mjtrb {
	int idx;
	struct mjtrb *next;
};

struct mjtrb *rballoc(int);
void rbfree(struct mjtrb *);


