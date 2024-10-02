#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#define INITLEN 3

/* We will use integers as our data type, but this could be anything */
typedef int data_t;

/* The stack type. d will be an array of data_t, which is the stack itself.
   n is a pointer to the head of the stack (technically the position to the
   right of the head as we will see later). currsize is the current size of the
   array which we will need to keep track of to ensure that we can allocate
   more memory if it gets full.*/
typedef struct {
    ... 
} stack_t;

stack_t *make_empty_stack();
void push(stack_t *s, data_t d);
data_t pop(stack_t *s);


/* A brief test of the stack function. Note that while it looks long, any real
   program will use the stack much much more than this, so there is still the
   possibility of bugs lurking. */
int
main(int argc, char** argv) {
    stack_t *s = make_empty_stack();
    
    push(s, 10);
    printf("Pushed: 10\n");
    push(s, 21);
    printf("Pushed: 21\n");
    push(s, 13);
    printf("Pushed: 13\n");
    push(s, 14);
    printf("Pushed: 14\n");
    push(s, 55);
    printf("Pushed: 55\n");
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    push(s, 36);
    printf("Pushed: 36\n");
    push(s, 17);
    printf("Pushed: 17\n");
    push(s, 29);
    printf("Pushed: 29\n");
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    push(s, 55);
    printf("Pushed: 55\n");
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    return 0;
}

/* We make an empty stack, making sure to allocate memory for the stack struct,
   as well as the stack (array) itself. These must be done seperately to allow
   us to grow the stack when needed. We also set initial values for the stack
   variables. */
stack_t
*make_empty_stack() {
    /* allocate memory for the stack struct */
    ...
    /* we have no items */
    ...
    /* set our default initial size of the array */
    ...
    /* allocate memory for the stack itself */
    /* In general, it is best to get the size of variables rather than types,
       e.g calling sizeof(*(s->d)) instead of sizeof(data_t). Since data_t
       is defined as the type of object in the stack, this is probably ok.
       sizeof(int) would be bad practice though.*/
    ...
    return s;
}

/* Push a data_t onto the stack. Note how we add the element before we
   increment the pointer to the head; this is because it points to the first
   free spot (which we determined in make_empty_stack when we set it to 0 for
   an empty stack). */
void
push(stack_t *s, data_t data) {
    /* if the stack is full, double the size */
    ...
        /* you might want to #define this 2, but it is probably ok as is */
        ...
    ...
}

/* Pops the item off the head of the stack, so long as there are items to be
   popped. */
data_t
pop(stack_t *s) {
    /* check to see if the stack is empty */
    ...

    printf("Tried to pop an empty stack!\n");
    /*This may or may not be an appropriate sentinal value, safer to use
      assert and exit entirely. Which should be used will depend on the context
      of the program calling it.*/
    return -1;
}
