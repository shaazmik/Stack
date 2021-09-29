#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define FATAL_ERROR assert(0)


struct pstack_info
{
    const long long Golub1 = 11333377;

    int* pstack_pointer;
    ssize_t pstack_size;
    ssize_t pstack_capacity;
    int pstack_error = 0;
    int pstack_inc = 0;
    size_t con_status = 0;
    size_t des_status = 0;

    const long long Golub2 = 11448888;
};

enum errors
{
    ERROR_OUT_RANGE = 1488,
    ERROR_FULL_STACK = 1945,
    ERROR_NAELSYA = 2718281828459045,
    ERROR_NULLPTR = 228,
    ERROR_DOUBLE_CONSTRUCT = 1555,
    ERROR_DOUBLE_DESTRUCT = 1337,
    ERROR_WRONG_CAPACITY = 1861,
    OK = 0
};


const int Pstack_inc_max = 3;


int stack_constructor(struct pstack_info* pstack, size_t pstack_user_size);


void check_construct(struct pstack_info* pstack);


void check_nullptr(struct pstack_info* pstack);



int stack_pushka(struct pstack_info* pstack, int new_element);



int stack_popka(struct pstack_info* pstack);



int verification(struct pstack_info* pstack);



int dump_loud(struct pstack_info* pstack, const char* name_of_file, const char* name_of_function);



void print_err_loud(int err_num, const char* name_of_file, const char* name_of_function);


int destructor(struct pstack_info* pstack);


void check_destruct(struct pstack_info* pstack);


#endif // STACK_H
