#include "Stack.h"


int pstack_resize(struct pstack_info* pstack)
{


}


#define DANYA_ZHOPA  = {}

#define $(value)     printf ("got result: " #value " = %d\n", (value))

#define $kekw        printf ("kekw on %d\n", __LINE__);

int main()
{
    //printf("Input your command:");

    struct pstack_info pstack DANYA_ZHOPA;

    int capacity = 0;
    printf ("Input stack capacity:\n");
    scanf ("%d", &capacity);

    stack_constructor (&pstack, capacity);
    //stack_constructor (&pstack, capacity);

    $( stack_pushka(&pstack, 5));
    $( stack_pushka(&pstack, 7));
    dump_loud(&pstack, __FILE__, __PRETTY_FUNCTION__);
    $( stack_popka(&pstack));
    $( stack_popka(&pstack));
    //$( stack_popka(&pstack));


    $( destructor  (&pstack) );

    return OK;
}
