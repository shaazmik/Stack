#include "Stack.h"


int stack_constructor(struct pstack_info* pstack, int pstack_user_size)
{
    check_nullptr(pstack);

    check_construct(pstack);

    if (pstack_user_size < 0)
    {
        printf("Negative value, take the number module\n\n");
        pstack_user_size = abs(pstack_user_size);
    }

    pstack->Golub_left  = Dog;
    pstack->Golub_right = Dog;

    pstack->des_status  = DES_STATUS_OK;

    pstack->pstack_size = 0;
    pstack->pstack_capacity = pstack_user_size;

    pstack->pstack_error = 0;
    pstack->pstack_inc = 0;

    pstack->pstack_pointer = (type_array*)calloc(pstack->pstack_capacity * sizeof(type_array) + 2 * sizeof(long long),
                                                 sizeof(char));

    if (check_memory(pstack->pstack_pointer))
    {
        printf("SIZE ERROR: TOO MUCH REQUESTED MEMORY\n"
               "DEFAULT SIZE OF STACK:%d\n\n ", Default_size_of_pstack);

        pstack->pstack_capacity = Default_size_of_pstack;

        free(pstack->pstack_pointer);

        pstack->pstack_pointer = (type_array*)calloc(pstack->pstack_capacity * sizeof(type_array) + 2 * sizeof(long long),
                                                 sizeof(char));
    }

    *pstack->pstack_pointer = pstack->Golub_left;

    pstack->pstack_pointer = (type_array*)((char*)pstack->pstack_pointer + 1 * sizeof(long long));

    *(pstack->pstack_pointer + pstack_user_size) = pstack->Golub_right;

    pstack->con_status = STACK_IS_CONSTURCTED;

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
    // realloc
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
    // realloc
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
