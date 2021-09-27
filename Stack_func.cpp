#include "Stack.h"


int stack_constructor(struct pstack_info* pstack, size_t pstack_user_size)
{
    check_nullptr(pstack);

    pstack->pstack_size = 0;
    pstack->pstack_capacity = pstack_user_size;
    pstack->pstack_error = 0;
    pstack->pstack_pointer = (int*)calloc(pstack_user_size, sizeof(int));
    pstack->pstack_incpwr = 0;

    return 0;
}


int stack_pushka(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    pstack->pstack_pointer++;


    if (verification(pstack))
    {
        dump(pstack);
        FATAL_ERROR;
    }


    int new_element = 0;
    scanf("%d", &new_element);

    *(pstack->pstack_pointer) = new_element;
    pstack->pstack_size++;

    return 0;
}


int stack_popka(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    pstack->pstack_size--;

    if (verification(pstack))
    {
        dump(pstack);
        FATAL_ERROR;
    }

    int pop_result = 0;

    pop_result = *pstack->pstack_pointer;

    pstack->pstack_pointer--;

    return pop_result;
}


int destructor(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    free(pstack->pstack_pointer);

    pstack->pstack_size = 0;
    pstack->pstack_error = 0;
    pstack->pstack_capacity = 0;
    pstack->pstack_pointer = (int*)('s');

    return 0;
}
