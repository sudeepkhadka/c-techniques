#include <stdio.h>
#include <stdlib.h>


/* 
                Stack Visualization
                        

Index:  ____0_______1_______2____________________________________________    
size-1  |      |        |       |       |       |       |       |       |
        |   3  |    2   |   1   |       |       |       |       |       |
        -----------------------------------------------------------------
        ^                   ^
       Top                First/base
 */

#define MAXSIZE 5
int stack_arr[MAXSIZE];     //can hold maximum 5 data/elements
int first = -1;

/**
 * @brief push() function: All data shifted to the right/next memblock, then, new data pushed to Top/first memblock
 *  stack_arr[counter] = stack_arr[counter - 1];
 * @param data 
 */
void push(int data);


/**
 * @brief pop() function: Top element/data is deleted/popped by shifting all elements to the left
 *                        But, must decrement the val of first by 1 as there will be 1 less elements
 * @param data 
 */
int pop();
// void pop(int data);

// typedef struct st_t { 
//     int *base;
//     int *top;
//     int size;
//     struct st_t *previous;} stack_t;

// stack_t *create_stack(int size)
// {
//     stack_t *st;
//     st = (stack_t *) malloc( sizeof(stack_t) );
//     st->base = (int*) malloc(size *sizeof(int) );
//     st->size = size;
//     st->top = st->base;
//     st->previous = NULL;
//     return( st );
// }


// int top_element(stack_t *st)
// { 
//     if( st->top == st->base )
//     return( *(st->previous->top -1) );
//     else
//         return( *(st->top -1) );
// }

// void remove_stack(stack_t *st)
// {
//     stack_t *tmp;
//     do
//     { 
//         tmp = st->previous;
//         free( st->base );
//         free( st );
//         st = tmp;
//     }while( st != NULL );
// }

void push(int data)
{
    
    first += 1;
    for (int counter = first; counter > 0; counter --)  //initialized only once 
    {
        stack_arr[counter] = stack_arr[counter - 1]; // memblock1 memblock2 memblock3      memblock2 now holds the data from memblock1
    }       //exits for loop if counter is not greater than 0 

    stack_arr[0] = data;    //assigns the data to the top/first_memblock
    /* if ( st->top < st->base + st->size )
    {
        *(st->top) = x; st->top += 1;
    }
    else
    {
        stack_t *new;
        new = (stack_t *) malloc( sizeof(stack_t) );
        new->base = st->base;
        new->top = st->top;
        new->size = st->size;
        new->previous = st->previous;
        st->previous = new;
        st->base = (int *) malloc( st->size * sizeof(int) );
        st->top = st->base + 1;
        *(st->base) = x;
    } */
}

// int pop(stack_t *st)
int pop()
{
    int value = 0;
    value = stack_arr[0];       //give me the first element
    for (int counter = 0; counter < first; counter++)
    {
        stack_arr[counter] = stack_arr[counter + 1];
    }
    first -= 1;
    return value;
    /* if( st->top == st->base )
    { 
        stack_t *old;
        old = st->previous;
        st->previous = old->previous;
        free( st->base );
        st->base = old->base;
        st->top = old->top;
        st->size = old->size;
        free( old );
    }
    st->top -= 1;
    return( *(st->top) ); */
}

int isEmpty()
{
    if (first == -1)
    {
        printf("stack is empty!\n");
        return -1;
    }
    else
    {
        // printf("stack is not Empty\n");
        return 0;
    }
    // return( st->base == st->top && st->previous == NULL);
}

int isFull()
{
    // printf("first: %d\n", first);
    int comp = MAXSIZE - 1;
    // printf("MAXSIZE - 1: %d\n", comp);
    if (5 <= first)
    {
        printf("Stack is Full!\n");
        return -1;
    }
    else
    {
        // printf("Stack is not Full yet!\n");
        return 0;
    }

}

int peek()
{
    if (isEmpty())
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        return stack_arr[0];
    }
}

void print()
{
    if (first == -1)
    {
        printf("Stack Underflow occured!\n");
    }
    
    for (int counter = 0; counter <= first; counter++)
    {
        printf("%d ", stack_arr[counter]);
    }
    printf("\n");
}

int main()
{
    int data = 0;
   
    printf("First is now: %d\nCheking if full...\n", first);
    isEmpty();
    do {
        push(100);
        push(50);
        push(399);
    } while (-1 != isFull());

    printf("First is now: %d\n", first);
    printf("Stack has %d elements\n", first + 1);
    print();

    printf("First is now: %d\nCheking if Empty...\n", first);
    while (-1 != isEmpty())
    {
        data = pop();
        printf("Element Popped: %d\n", data);
        printf("First is now: %d\n", first);
    }
    data = peek();
    printf("\nElement Peeked!: %d\n", data);
    print();

    return 0;    
}

void custom_free(void *mem_addr)
{
    if (mem_addr)
    {
        free(mem_addr);
    }
}

