#include <stdio.h>

#define MAXSIZE 40
#define item_t int

int i=0;
item_t stack[MAXSIZE];

int stack_empty(void) {
    return(i == 0);
}

int push(item_t x) {
    if (i < MAXSIZE) {
	stack[i++] = x; return(0);
    } else
	return(-1);
}

item_t pop(void) {
    return (stack[--i]);
}

int main() {
    push(3);
    push(5);
    printf("%d", pop());
    printf("%d", pop());
}
