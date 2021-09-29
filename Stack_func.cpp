#include "Stack.h"


int stack_constructor(struct pstack_info* pstack, size_t pstack_user_size)
{
    check_nullptr(pstack);

    pstack->con_status++;

    check_construct(pstack);

    pstack->pstack_size = 0;
    pstack->pstack_capacity = pstack_user_size;
    pstack->pstack_error = 0;
    pstack->pstack_pointer = (int*)calloc(pstack_user_size, sizeof(int));
    pstack->pstack_inc = 0;

    return OK;
}


int stack_pushka(struct pstack_info* pstack, int new_element)
{
    check_nullptr(pstack);

    pstack->pstack_size++;

    if (verification(pstack))
    {
        pstack->pstack_size--;
        dump_loud(pstack, __FILE__, __PRETTY_FUNCTION__);
    }


    pstack->pstack_pointer[pstack->pstack_size] = new_element;

    return 0;
}


int stack_popka(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    pstack->pstack_size--;

    if (verification(pstack))
    {
        pstack->pstack_size++;
        dump_loud(pstack, __FILE__, __PRETTY_FUNCTION__);
    }

    int pop_result = 0;

    pop_result = pstack->pstack_pointer[pstack->pstack_size + 1];

    return pop_result;
}


int destructor(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    pstack->des_status++;

    check_destruct(pstack);

    free(pstack->pstack_pointer);
    pstack->pstack_size = 0;
    pstack->pstack_error = 0;
    pstack->pstack_capacity = 0;
    pstack->pstack_pointer = (int*)('s');

    FILE* log = fopen("log.txt", "w");
    fclose(log);

    return OK;
}
