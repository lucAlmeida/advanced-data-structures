#include <stdio.h>
#include <stdlib.h>

#define BLOCKSIZE 256

#define def_node(item_t, node_t)            \
typedef struct nd_t { struct nd_t *next;    \
                      item_t item; } node_t;
#define item_t int
#define node_t stack_t
def_node(item_t, node_t);

// Variables of the node
node_t *currentblock = NULL;
int size_left;
node_t *free_list = NULL;
// Node functions
node_t *get_node() {
    node_t *tmp;
    if (free_list != NULL) {
	tmp = free_list;
	free_list = free_list->next;
    } else {
	if (currentblock == NULL || size_left == 0) {
	    currentblock = (node_t *) malloc(BLOCKSIZE * sizeof(node_t));
	    size_left = BLOCKSIZE;
	}
	tmp = currentblock++;
	size_left -= 1;
    }
    return tmp;
}

void return_node(node_t *node) {
    node->next = free_list;
    free_list = node;
}
// Stack functions
stack_t *create_stack(void) {
    stack_t *st;
    st = get_node();
    st->next = NULL;
    return (st);
}

int stack_empty(stack_t *st) {
    return (st->next == NULL);
}

void push(item_t x, stack_t *st) {
    stack_t *tmp;
    tmp = get_node();
    tmp->item = x;
    tmp->next = st->next;
    st->next = tmp;
}

item_t pop(stack_t *st) {
    stack_t *tmp; item_t tmp_item;
    tmp = st->next;
    st->next = tmp->next;
    tmp_item = tmp->item;
    return_node(tmp);
    return(tmp_item);
}

item_t top_element(stack_t *st) {
    return (st->next->item);
}

void remove_stack(stack_t *st) {
    stack_t *tmp;
    do {
	tmp = st->next;
	return_node(st);
	st = tmp;
    } while(tmp != NULL);
}

int main() {
    stack_t* a_stack = create_stack();
    push(3, a_stack);
    push(17, a_stack);
    printf("%d\n", pop(a_stack));
    printf("%d\n", pop(a_stack));
}
