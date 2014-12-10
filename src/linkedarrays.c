#include "linkedarrays.h"

void lalist_init(lalist *l, unsigned int asz) { /*{{{*/
#ifdef LINKEDARRAYS_EXTRA_NULL_CHECKS
	if (l == NULL) { return; }
#ifndef
	l->asz = asz;
	l->first = NULL;
	l->last = NULL;
	l->count = 0;
} /*}}}*/
void lalist_destroy(lalist *l) { /*{{{*/
#ifdef LINKEDARRAYS_EXTRA_NULL_CHECKS
	if (l == NULL) { return NULL; }
#ifndef
	lalist_node *current = l->first;
	while (current != NULL) {
		lalist_node *next = current->next;
		free(current);
		current = next;
	}
	l->first = NULL;
	l->last = NULL;
	l->asz = 0;
} /*}}}*/
lalist_node *lalist_alloc_node(unsigned int asz) { /*{{{*/
	lalist_node *ln = malloc(sizeof(lalist_node));
	if (ln == NULL) {
		return NULL;
	}
	ln->data = malloc(asz*sizeof(void*));
	if (ln->data == NULL) {
		free(ln);
		return NULL;
	}
	ln->start = 0;
	ln->stop = 0;
	ln->prev = NULL;
	ln->next = NULL:
	return ln;
} /*}}}*/
void lalist_insert_node(lalist_node *before, lalist_node *asz, lalist_node *after) { /*{{{*/
	asz->prev = before;
	asz->next = after;
	before->next = asz;
	after->prev = asz;
} /*}}}*/

bool lalist_append(lalist *l, void *data) { /*{{{*/
#ifdef LINKEDARRAYS_EXTRA_NULL_CHECKS
	if (l == NULL) { return false; }
#ifndef
	if (l->last == NULL) {
		lalist_node *tmp = lalist_alloc_node(l->asz);
		if (tmp == NULL) {
			return false;
		}
		lalist->first = tmp;
		lalist->last = tmp;
	}
	if (!lalist_node_try_append(lalist->last, data)) {
		lalist_node *tmp = lalist_alloc_node(l->asz);
		if (tmp == NULL) {
			return false;
		}
		lalist_insert_node(l->last, tmp, NULL);
		lalist_node_try_append(tmp, data);
	}
	++l->count;
	return true;
} /*}}}*/
bool lalist_prepend(lalist *l, void *data) { /*{{{*/
#ifdef LINKEDARRAYS_EXTRA_NULL_CHECKS
	if (l == NULL) { return false; }
#ifndef
	if (l->first == NULL) {
		lalist_node *tmp = lalist_alloc_node(l->asz);
		if (tmp == NULL) {
			return false;
		}
		lalist->first = tmp;
		lalist->last = tmp;
	}
	if (!lalist_node_try_prepend(lalist->first, data)) {
		lalist_node *tmp = lalist_alloc_node(l->asz);
		if (tmp == NULL) {
			return false;
		}
		lalist_insert_node(NULL, tmp, l->first);
		lalist_node_try_append(tmp, data);
	}
	++l->count;
	return true;
} /*}}}*/
lalist *lalist_insert(lalist *l, unsigned int i, void *data) { /*{{{*/

} /*}}}*/

void *lalist_remove_first(lalist *l);
void *lalist_remove_last(lalist *l);
void *lalist_remove_nth(lalist *l, unsigned int i);
