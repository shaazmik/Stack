#include "Stack.h"


int stack_constructor(struct pstack_info* pstack, size_t pstack_user_size)
{
    check_nullptr(pstack);

    check_construct(pstack);
    pstack->Golub_left = Dog;
    pstack->Golub_right = Dog;
    pstack->des_status = DES_STATUS_OK;
    pstack->pstack_size = 0;
    pstack->pstack_capacity = pstack_user_size;
    pstack->pstack_error = 0;
    pstack->pstack_pointer = (type_array*)calloc(pstack_user_size * sizeof(type_array) + 2 * sizeof(long long),
                                                 sizeof(char));
    *pstack->pstack_pointer = pstack->Golub_left;
    pstack->pstack_pointer = (type_array*)((char*)pstack->pstack_pointer + 1 * sizeof(long long));
    *(pstack->pstack_pointer + pstack_user_size) = pstack->Golub_right;
    pstack->pstack_inc = 0;

    pstack->con_status++;

    if (verification(pstack))
    {
        dump_loud(pstack, __FILE__, __PRETTY_FUNCTION__);
    }

    return OK;
}

int pstack_resizemo(struct pstack_info* pstack)
{
    pstack->pstack_capacity += Pstack_multiplier;
    pstack->pstack_pointer = (type_array*)realloc( (char*)pstack->pstack_pointer - 1 * sizeof(long long),
                                                   pstack->pstack_capacity * sizeof(type_array)
                                                   + 2 * sizeof(long long) );
    pstack->pstack_pointer = (type_array*)((char*)pstack->pstack_pointer + 1 * sizeof(long long));
    pstack->inc_counter++;
    return WARNING_SIZE_INC;
}


int pstack_resizele(struct pstack_info* pstack)
{
    pstack->pstack_capacity -= Pstack_multiplier;
    pstack->pstack_pointer = (type_array*)realloc( (char*)pstack->pstack_pointer - 1 * sizeof(long long),
                                                   pstack->pstack_capacity * sizeof(type_array)
                                                   + 2 * sizeof(long long) );
    pstack->pstack_pointer = (type_array*)((char*)pstack->pstack_pointer + 1 * sizeof(long long));
    pstack->inc_counter--;

    return WARNING_SIZE_DEC;
}


int stack_pushka(struct pstack_info* pstack, type_array new_element)
{
    check_nullptr(pstack);

    if (verification(pstack))
    {
        dump_loud(pstack, __FILE__, __PRETTY_FUNCTION__);
    }

    if ((pstack->pstack_size == pstack->pstack_capacity) && (pstack->inc_counter <= Pstack_inc_max))
    {
        pstack->pstack_error = pstack_resizemo(pstack);
        pstack->pstack_pointer[pstack->pstack_size] = new_element;
        pstack->pstack_size++;
        dump_loud(pstack, __FILE__, __PRETTY_FUNCTION__);
    }
    else
    {
        pstack->pstack_pointer[pstack->pstack_size] = new_element;
        pstack->pstack_size++;
    }


    if (verification(pstack))
    {
        dump_loud(pstack, __FILE__, __PRETTY_FUNCTION__);
    }

    return OK;
}


type_array stack_popka(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    if (verification(pstack))
    {
        dump_loud(pstack, __FILE__, __PRETTY_FUNCTION__);
    }
    pstack->pstack_size--;
    type_array pop_result = 0;
    pop_result = pstack->pstack_pointer[pstack->pstack_size];


    if (verification(pstack))
    {
        dump_loud(pstack, __FILE__, __PRETTY_FUNCTION__);
    }

    if ( (pstack->pstack_size == pstack->pstack_capacity - 2 * Pstack_multiplier) && (pstack->inc_counter > 1))
    {
        pstack->pstack_error = pstack_resizele(pstack);
        dump_loud(pstack, __FILE__, __PRETTY_FUNCTION__);
    }


    return pop_result;
}



int destructor(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    check_destruct(pstack);

    free((char*)pstack->pstack_pointer - 1 * sizeof(long long));
    pstack->pstack_pointer = pstack->pstack_pointer - 1 * sizeof(long long);
    pstack->pstack_pointer = nullptr;
    pstack->pstack_size = 0;
    pstack->pstack_error = 0;
    pstack->pstack_capacity = 0;

    FILE* log = fopen("log.txt", "w");
    fclose(log);

    pstack->des_status++;

    return OK;
}
