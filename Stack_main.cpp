#include "Stack.h"


int dump(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    if (pstack->pstack_error == ERROR_NULLPTR)
    {
        printf("ERROR_NULLPTR #%d\n", ERROR_NULLPTR);
        return ERROR_NULLPTR;
    }

    if  (pstack->pstack_error == ERROR_OUT_RANGE)
    {
        printf("ERROR_OUT_OF_RANGE #%d\n", ERROR_OUT_RANGE);
        return ERROR_OUT_RANGE;
    }

    if (pstack->pstack_error == ERROR_FULL_STACK);
    {
        printf("ARA ARA NEMA SPACE #%d\n", ERROR_FULL_STACK);
        return ERROR_FULL_STACK;
    }




    return 0;
}



int pstack_resize(struct pstack_info* pstack)
{

}




int verification(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    if (pstack->pstack_pointer == nullptr) return ERROR_NULLPTR;

    if (pstack->pstack_size > pstack->pstack_capacity)
    {
        pstack->pstack_error = ERROR_FULL_STACK;
        return ERROR_FULL_STACK;
    }

    if (pstack->pstack_size < 0 )
    {
        pstack->pstack_error = ERROR_OUT_RANGE;
        return ERROR_OUT_RANGE;
    }

    return 0;
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
    $( pstack.Golub2);
    $( stack_pushka (&pstack) );
    $( stack_pushka (&pstack) );
   // $( stack_pushka (&pstack) );

    $( stack_popka (&pstack) );
    $( stack_popka (&pstack) );
    $kekw;
    //$( stack_popka (&pstack) );
    $( destructor  (&pstack) );
}
