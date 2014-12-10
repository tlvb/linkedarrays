#ifndef LINKEDARRAYS_H
#define LINKEDARRAYS_H

typedef struct lalist_node {
	struct lalist_node *prev;
	struct lalist_node *next;
	void **data;
	unsigned int start;
	unsigned int stop;
} lalist_node;

typedef struct {
	lalist_node *first;
	lalist_node *last;
	unsigned int asz;
	unsigned int count;
} lalist;

void lalist_init(lalist *l, unsigned int asz);
void lalist_destroy(lalist *l);
lalist_node *lalist_alloc_node(unsigned int asz);
void lalist_insert_node(lalist_node *before, lalist_node *asz, lalist_node *after);

bool lalist_append(lalist *l, void *data);
bool lalist_prepend(lalist *l, void *data);
bool lalist_insert(lalist *l, unsigned int i, void *data);

void *lalist_remove_first(lalist *l);
void *lalist_remove_last(lalist *l);
void *lalist_remove_nth(lalist *l, unsigned int i);

bool lalist_node_try_append(lalist_node *ln, data);
bool lalist_node_try_prepend(lalist_node *ln, data);


#endif
