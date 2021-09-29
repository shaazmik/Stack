#include "Stack.h"


void check_nullptr(struct pstack_info* pstack)
{
    if (pstack == nullptr)
    {
            FILE* log = fopen("log.txt", "a");
            fprintf(log, "Stack [NULL_PTR_ERROR #%d] [0x000000]\n ", ERROR_NULLPTR);

            fflush(log);

            FATAL_ERROR;
    }
}

void check_construct(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    if (pstack->con_status > 1)
    {
        printf("ERROR: check 'log.txt'\n\n");
        FILE* log = fopen("log.txt", "a");
        fprintf(log, "Stack [RE-CREATING_STACK_ERROR #%d] \n", ERROR_DOUBLE_CONSTRUCT);

        fflush(log);

        FATAL_ERROR;
    }
}

void check_destruct(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    if (pstack->des_status > 1)
    {
        printf("ERROR: check 'log.txt'\n\n");
        FILE* log = fopen("log.txt", "a");
        fprintf(log, "Stack [RE-DESTRUCTING_STACK_ERROR #%d] \n", ERROR_DOUBLE_DESTRUCT);

        fflush(log);

        FATAL_ERROR;
    }
}

int verification(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    if (pstack->pstack_size == pstack->pstack_capacity)
    {

    }

    if (pstack->pstack_pointer == nullptr)
    {
        pstack->pstack_error = ERROR_NULLPTR;
        return ERROR_NULLPTR;
    }

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


int dump_loud(struct pstack_info* pstack, const char* name_of_file, const char* name_of_func)
{
    check_nullptr(pstack);

    printf("STACK CAPACITY:%d\n", pstack->pstack_capacity);
    printf("STACK SIZE:%d\n", pstack->pstack_size);
    printf("STACK'S TOP ELEMENT:%d\n", pstack->pstack_pointer[pstack->pstack_size]);
    printf("STACK LEFT CANARY:%d\n", pstack->Golub1);
    printf("STACK RIGHT CANART:%d\n", pstack->Golub2);

    switch(pstack->pstack_error)
    {
        case ERROR_OUT_RANGE:
            print_err_loud(ERROR_OUT_RANGE, name_of_file, name_of_func);
            break;
        case ERROR_FULL_STACK:
            print_err_loud(ERROR_FULL_STACK, name_of_file, name_of_func);
            break;
        case ERROR_NULLPTR:
            print_err_loud(ERROR_NULLPTR, name_of_file, name_of_func);
            break;
        default:
            break;
    }
    return OK;
}


void print_err_loud(int err_num, const char* name_of_file, const char* name_of_function)
{
    printf("\nERROR NUMBER #%d, check 'log.txt' \n\n", err_num);

    FILE* log = fopen("log.txt", "a");
    fprintf(log, "Stack [Error #%d] in file \"%s\" function \"%s\" \n", err_num, name_of_file, name_of_function );

    fflush(log);

    FATAL_ERROR;
}
