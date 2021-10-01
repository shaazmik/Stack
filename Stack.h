#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define FATAL_ERROR assert(0)

typedef double type_array;

enum errors
{
    OK = 0,
    CON_STATUS_OK = 3,
    DES_STATUS_OK = 13,
    ERROR_OUT_RANGE = 1488,
    ERROR_FULL_STACK = 1945,
    ERROR_NULLPTR = 228,
    ERROR_DOUBLE_CONSTRUCT = 1555,
    ERROR_DOUBLE_DESTRUCT = 1337,
    ERROR_WRONG_CAPACITY = 1861,
    WARNING_SIZE_INC = 666,
    WARNING_SIZE_DEC = 999
};


struct pstack_info
{
    const long long Golub1 = 11333377;

    type_array* pstack_pointer;
    int pstack_size;
    ssize_t pstack_capacity;
    int pstack_error = 0;
    int pstack_inc = 0;
    size_t con_status = CON_STATUS_OK;
    size_t des_status;
    size_t inc_counter = 1;
    long long p_hash = 0;


    const long long Golub2 = 11448888;
};


const int Pstack_inc_max = 3;


const int Pstack_multiplier = 2;


int stack_constructor(struct pstack_info* pstack, size_t pstack_user_size);


void check_construct(struct pstack_info* pstack);


void check_nullptr(struct pstack_info* pstack);


int stack_pushka(struct pstack_info* pstack, type_array new_element);


type_array stack_popka(struct pstack_info* pstack);


int verification(struct pstack_info* pstack);


int pstack_resizemo(struct pstack_info* pstack);


int pstack_resizele(struct pstack_info* pstack);


int dump_loud(struct pstack_info* pstack, const char* name_of_file, const char* name_of_function);


void print_err_loud(int err_num, const char* name_of_file, const char* name_of_function, pstack_info* pstack, int line_number);


int destructor(struct pstack_info* pstack);


void check_destruct(struct pstack_info* pstack);


#endif // STACK_H
