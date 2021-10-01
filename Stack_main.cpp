#include "Stack.h"

#define DANYA_ZHOPA  = {}

#define $(value)     { printf ("got result: " #value " = %d", value); printf ("\n"); }

#define $kekw        printf ("kekw on %d\n", __LINE__);

void dump (int value)       { printf ("%d",  value); }
void dump (double value)    { printf ("%lg", value); }
void dump (const char* str) { printf ("%s",  str);   }

int main()
{
    //printf("Input your command:");

    struct pstack_info pstack DANYA_ZHOPA;

    int capacity = 0;
    printf ("Input stack capacity:\n");
    scanf ("%d", &capacity);
    stack_constructor (&pstack, capacity);
    //$( destructor  (&pstack) );

    //stack_constructor (&pstack, capacity);

    $( stack_pushka(&pstack, 5));

    $( stack_pushka(&pstack, 7));

    $( stack_popka(&pstack));

    $( stack_popka(&pstack));

    //$( stack_popka(&pstack));


    $( destructor  (&pstack) );

    return OK;
}
