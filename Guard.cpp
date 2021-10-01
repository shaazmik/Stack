#include "Stack.h"


void check_nullptr(struct pstack_info* pstack)
{
    if (pstack == nullptr)
    {
            FILE* log = fopen("log.txt", "a");
            assert(log != nullptr);

            fprintf(log, "Stack [NULL_PTR_ERROR #%d] [0x000000]\n ", ERROR_NULLPTR);

            fflush(log);

            FATAL_ERROR;
    }
}

void check_construct(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    if (pstack->con_status != CON_STATUS_OK)
    {
        printf("ERROR: check 'log.txt'\n\n");

        FILE* log = fopen("log.txt", "a");
        assert(log != nullptr);

        fprintf(log, "Stack [RE-CREATING_STACK_ERROR OR NOT INITILIZATION #%d] \n", ERROR_DOUBLE_CONSTRUCT);

        fflush(log);

        FATAL_ERROR;
    }
}

void check_destruct(struct pstack_info* pstack)
{
    check_nullptr(pstack);

    if (pstack->des_status != DES_STATUS_OK)
    {
        printf("ERROR: check 'log.txt'\n\n");

        FILE* log = fopen("log.txt", "a");
        assert(log != nullptr);

        fprintf(log, "Stack [RE-DESTRUCTING_STACK_ERROR OR EMPTY DESTRUCTING #%d] \n", ERROR_DOUBLE_DESTRUCT);

        fflush(log);

        FATAL_ERROR;
    }
}

int verification(struct pstack_info* pstack)
{
    check_nullptr(pstack);

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

    printf("\n\nSTACK CAPACITY:      %d\n", pstack->pstack_capacity);
    printf("STACK SIZE:          %d\n", pstack->pstack_size);
    if (pstack->pstack_error != ERROR_NULLPTR)
    {
        printf("STACK'S TOP ELEMENT: %d\n", pstack->pstack_pointer[pstack->pstack_size - 1]);
    }
    else
    {
        printf("STACK HASN'T TOP ELEMENT : NULLPTR\n");
    }
    printf("STACK LEFT CANARY:   %d\n", pstack->Golub1);
    printf("STACK RIGHT CANARY:  %d\n\n", pstack->Golub2);

    switch(pstack->pstack_error)
    {
        case ERROR_OUT_RANGE:
            print_err_loud(ERROR_OUT_RANGE, name_of_file, name_of_func, pstack, __LINE__);
            break;
        case ERROR_FULL_STACK:
            print_err_loud(ERROR_FULL_STACK, name_of_file, name_of_func, pstack, __LINE__);
            break;
        case ERROR_NULLPTR:
            print_err_loud(ERROR_NULLPTR, name_of_file, name_of_func, pstack, __LINE__);
            break;
        case WARNING_SIZE_DEC:
            pstack->pstack_error = 0;
            printf("STACK HAS BEEN DECREASED\n\n");
            break;
        case WARNING_SIZE_INC:
            pstack->pstack_error = 0;
            printf("STACK HAS BEEN INCREASED\n\n");
            break;
        default:
            break;
    }
    return OK;
}


void print_err_loud(int err_num, const char* name_of_file, const char* name_of_function, pstack_info* pstack, int line_number)
{
    printf("\nERROR NUMBER #%d, check 'log.txt' \n\n", err_num);

    FILE* log = fopen("log.txt", "a");
    assert(log != nullptr);


    fprintf(log, "Stack [Error #%d] in file \"%s\" function \"%s\" dump alerted on \"%d\" line \n",
            err_num, name_of_file, name_of_function, line_number );
    fprintf(log, "\n\nSTACK CAPACITY:%d\n", pstack->pstack_capacity);
    fprintf(log, "STACK SIZE:%d\n", pstack->pstack_size);
    if (pstack->pstack_error != ERROR_NULLPTR)
    {
        fprintf(log, "STACK'S TOP ELEMENT: %d\n", pstack->pstack_pointer[pstack->pstack_size - 1]);
    }
    else
    {
        fprintf(log, "STACK HASN'T TOP ELEMENT : NULLPTR\n");
    }
    fprintf(log, "STACK LEFT CANARY:%d\n", pstack->Golub1);
    fprintf(log, "STACK RIGHT CANARY:%d\n\n", pstack->Golub2);

    fflush(log);

    FATAL_ERROR;
}
