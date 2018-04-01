#include <stdio.h>
#include <stdlib.h>

#define def_struct(item_t, stack_t)        \
typedef struct {item_t *base; item_t *top; \
                int size;} stack_t;

#define item_t int
#define stack_t int_stack
def_struct(item_t, stack_t);

stack_t *create_stack(int size)
{
    stack_t *st;
    st = (stack_t *) malloc(sizeof(stack_t));
    st->base = (item_t *) malloc(size * sizeof(item_t));
    st->size = size;
    st->top = st->base;
    return (st);
}

int stack_empty(stack_t *st) 
{
    return (st->base == st->top);
}

int push(item_t x, stack_t *st)
{
    printf("st->top: %p, st->base: %p, st->base + size: %p\n",
           st->top, st->base, st->top+st->size);
    if (st->top < st->base + st->size) {
	*(st->top) = x; st->top += 1; return(0);
    } else {
	return (-1);
    }
}

item_t pop(stack_t *st)
{
    st->top -= 1;
    return (*(st->top));
}

item_t top_element(stack_t *st)
{
    return (*(st->top -1));
}

void remove_stack(stack_t *st)
{
    free(st->base);
    free(st);
}


int main()
{
    stack_t* a_stack = create_stack(4);
    push(3, a_stack);
    printf("%d\n", pop(a_stack));
}
